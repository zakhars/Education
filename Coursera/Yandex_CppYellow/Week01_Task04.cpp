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
   const TasksInfo& GetPersonTasksInfo(const string& person) const;

   // Add task (in NEW status) for person
   void AddNewTask(const string& person);

   // Update statuses for task_count tasks for given person
   tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count);

private:

   TaskStatus nextStatus(TaskStatus ts)
   {
      switch (ts)
      {
         case TaskStatus::NEW: return TaskStatus::IN_PROGRESS;
         case TaskStatus::IN_PROGRESS: return TaskStatus::TESTING;
         case TaskStatus::TESTING: return TaskStatus::DONE;
      }
      return TaskStatus::DONE;
   }

   map<string, TasksInfo> m_personTasks;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string & person) const
{
   // Skip check person exists as it is impossible per task description
   return m_personTasks.at(person);
}

void TeamTasks::AddNewTask(const string & person)
{
   m_personTasks[person][TaskStatus::NEW]++;
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string& person, int task_count)
{
   const TasksInfo& tasks = m_personTasks[person];
   TasksInfo updatedTasks;
   TasksInfo remainingTasks = tasks; // except those which are DONE

   for (const auto& [status, count] : tasks)
   {
      if (status != TaskStatus::DONE && task_count > 0)
      {
         TaskStatus next_status = nextStatus(status);
         if (count < task_count)
         {
            updatedTasks[next_status] = count;
            remainingTasks.erase(status);
            task_count -= count;
         }
         else
         {
            updatedTasks[next_status] = task_count;
            remainingTasks[status] -= task_count;
            task_count = 0;
         }
      }
   }


   return tie(updatedTasks, remainingTasks);
}



// Get dict by value to be able to address absent keys with [] and get 0
// without changing original dictionary
void PrintTasksInfo(TasksInfo tasks_info) 
{
   cout << tasks_info[TaskStatus::NEW] << " new tasks" << ", " 
        << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" << ", " 
        << tasks_info[TaskStatus::TESTING] << " tasks are being tested" << ", " 
        << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() 
{
   TeamTasks tasks;
   tasks.AddNewTask("Ilia");
   for (int i = 0; i < 3; ++i) 
   {
      tasks.AddNewTask("Ivan");
   }
   cout << "Ilia's tasks: ";
   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
   cout << "Ivan's tasks: ";
   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

   TasksInfo updated_tasks, untouched_tasks;

   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
   cout << "Updated Ivan's tasks: ";
   PrintTasksInfo(updated_tasks);
   cout << "Untouched Ivan's tasks: ";
   PrintTasksInfo(untouched_tasks);

   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
   cout << "Updated Ivan's tasks: ";
   PrintTasksInfo(updated_tasks);
   cout << "Untouched Ivan's tasks: ";
   PrintTasksInfo(untouched_tasks);

   return 0;
}
