#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
    // Get tasks status for given person
    const TasksInfo& GetPersonTasksInfo(const string& person) const
    {
        // Skip check person exists as it is impossible per task description
        return m_personTasks.at(person);
    }

    // Add task (in NEW status) for person
    void AddNewTask(const string& person)
    {
        m_personTasks[person][TaskStatus::NEW]++;
    }

    // Update statuses for task_count tasks for given person
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
    {
        TasksInfo& initialTasks = m_personTasks[person];
        TasksInfo updatedTasks;

        for (auto ts : initialTasks)
        {
            if (ts.first == TaskStatus::DONE) break;
            updateCounts(ts.second, task_count);
            if (ts.second > 0)
            {
                updatedTasks[nextStatus(ts.first)] = ts.second;
            }
            if (task_count == 0)
            {
                break;
            }
        }

        for (const auto& ts : updatedTasks)
        {
            initialTasks[prevStatus(ts.first)] -= ts.second;
        }

        TasksInfo untouchedIncompleteTasks;
        for (const auto& ts : initialTasks)
        {
            if (ts.second > 0 && ts.first != TaskStatus::DONE)
            {
                untouchedIncompleteTasks[ts.first] = ts.second;
            }
        }

        for (const auto& ts : updatedTasks)
        {
            if (ts.second > 0)
            {
                initialTasks[ts.first] += ts.second;
            }
        }

        return tie(updatedTasks, untouchedIncompleteTasks);
    }

private:

    TaskStatus nextStatus(TaskStatus ts)
    {
        switch (ts)
        {
        case TaskStatus::NEW: return TaskStatus::IN_PROGRESS;
        case TaskStatus::IN_PROGRESS: return TaskStatus::TESTING;
        }
        return TaskStatus::DONE;
    }

    TaskStatus prevStatus(TaskStatus ts)
    {
        switch (ts)
        {
        case TaskStatus::TESTING: return TaskStatus::IN_PROGRESS;
        case TaskStatus::DONE: return TaskStatus::TESTING;
        }
        return TaskStatus::NEW;
    }

    void updateCounts(int& count, int& count_total)
    {
        if (count_total <= count)
        {
            count = count_total;
            count_total = 0;
        }
        else
        {
            count_total -= count;
        }
    }

    map<string, TasksInfo> m_personTasks;
};


// Get dict by value to be able to address absent keys with [] and get 0
// without changing original dictionary
void PrintTasksInfo(TasksInfo tasks_info)
{ 
    cout << " new: " << tasks_info[TaskStatus::NEW] << ", "
         << " progress: " << tasks_info[TaskStatus::IN_PROGRESS] << ", "
         << " testing: " << tasks_info[TaskStatus::TESTING] << ", "
         << " done: " << tasks_info[TaskStatus::DONE] << endl;
}

int main_week01_task05_ycpp()
{
    TeamTasks tasks;
    for (int i = 0; i < 3; ++i)
    {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ivan's tasks:           ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    for (int i = 0; i < 13; ++i)
    {
        tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
        cout << "Updated  : ";
        PrintTasksInfo(updated_tasks);
        cout << "Untouched: ";
        PrintTasksInfo(untouched_tasks);
        cout << "All      : ";
        PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
    }

    return 0;
}

// Teacher's solution:

/*
// Выделим в отдельную функцию получение следующего по приоритету типа задачи
// Функция налагает требование на входной параметр: он не должен быть равен DONE
// При этом task_status явно не сравнивается с DONE, что позволяет
// сделать эту функцию максимально эффективной
TaskStatus Next(TaskStatus task_status) {
  return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const;

  // Добавить новую задачу (в статусе NEW) для конкретного разработчика
  void AddNewTask(const string& person);

  // Обновить статусы по данному количеству задач конкретного разработчика
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count);

private:
  map<string, TasksInfo> person_tasks_;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
  return person_tasks_.at(person);
}

void TeamTasks::AddNewTask(const string& person) {
  ++person_tasks_[person][TaskStatus::NEW];
}

// Функция для удаления нулей из словаря
void RemoveZeros(TasksInfo& tasks_info) {
  // Соберём те статусы, которые нужно убрать из словаря
  vector<TaskStatus> statuses_to_remove;
  for (const auto& task_item : tasks_info) {
    if (task_item.second == 0) {
      statuses_to_remove.push_back(task_item.first);
    }
  }
  for (const TaskStatus status : statuses_to_remove) {
    tasks_info.erase(status);
  }
}


tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(
    const string& person, int task_count) {
  TasksInfo updated_tasks, untouched_tasks;
  
  // Здесь и далее мы будем пользоваться тем фактом, что в std::map оператор [] 
  // в случае отсутствия ключа инициализирует значение по умолчанию,
  // если это возможно.
  // std::map::operator[] ->
  // http://ru.cppreference.com/w/cpp/container/map/operator_at
  TasksInfo& tasks = person_tasks_[person];

  // Посчитаем, сколько задач каждого из статусов нужно обновить, 
  // пользуясь тем фактом, что по умолчанию enum class инциализирует значения
  // от нуля по возрастанию.
  // enum class -> http://ru.cppreference.com/w/cpp/language/enum
  for (TaskStatus status = TaskStatus::NEW;
       status != TaskStatus::DONE;
       status = Next(status)) {
    // Считаем обновлённые
    updated_tasks[Next(status)] = min(task_count, tasks[status]);
    // Считаем, сколько осталось обновить
    task_count -= updated_tasks[Next(status)];
  }

  // Обновляем статус текущих задач в соответствии с информацией об обновлённых 
  // и находим количество нетронутых
  for (TaskStatus status = TaskStatus::NEW;
       status != TaskStatus::DONE;
       status = Next(status)) {
    untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
    tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
  }
  // По условию, DONE задачи не нужно возвращать в не обновлённых задачах
  tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

  // По условию в словарях не должно быть нулей
  RemoveZeros(updated_tasks);
  RemoveZeros(untouched_tasks);

  return {updated_tasks, untouched_tasks};
}

*/