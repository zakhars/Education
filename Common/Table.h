#include <stdio.h>
 
struct table_row {
  int id;
  char* name;
  char* role;
  int age;
}; 

/*

table_row people[] = 
{
  {3, "Jake Smith", "Tester", 27},
  {5, "Michael Brown", "Designer", 34},
  {2, "Zack Bernhardt", "Manager", 36}
}
 
const int people_length = sizeof(people) / sizeof(people[0]);

size_t i = 2; 
printf("Name: %s\n", people[i].name);
printf("Role: %s\n", people[i].role);
printf("Age: %d\n", people[i].age);

*/