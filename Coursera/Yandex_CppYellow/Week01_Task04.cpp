#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

// ������������ ��� ��� ������� ������
enum class TaskStatus {
   NEW,          // �����
   IN_PROGRESS,  // � ����������
   TESTING,      // �� ������������
   DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

class TeamTasks 
{
public:
   // �������� ���������� �� �������� ����� ����������� ������������
   const TasksInfo& GetPersonTasksInfo(const string& person) const;

   // �������� ����� ������ (� ������� NEW) ��� ����������� �������������
   void AddNewTask(const string& person);

   // �������� ������� �� ������� ���������� ����� ����������� ������������,
   // ����������� ��. ����
   tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count);

private:

   TaskStatus getNextStatus(TaskStatus ts)
   {
      switch (ts)
      {
         case TaskStatus::NEW: return TaskStatus::IN_PROGRESS;
         case TaskStatus::IN_PROGRESS: return TaskStatus::TESTING;
         case TaskStatus::TESTING: return TaskStatus::DONE;
      }
   }

   map<string, TasksInfo> personTasks;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string & person) const
{
   return personTasks.at(person);
}

void TeamTasks::AddNewTask(const string & person)
{
   personTasks[person][TaskStatus::NEW]++;
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string& person, int task_count)
{
   auto& tasks = personTasks[person];
   TasksInfo updatedTasks;

   for (auto& status: tasks)
   {
      
   }


   return tie(updatedTasks, tasks);
}



// ��������� ������� �� ��������, ����� ����� �����������
// ���������� � ������������� ������ � ������� [] � �������� 0,
// �� ����� ��� ���� �������� �������
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
