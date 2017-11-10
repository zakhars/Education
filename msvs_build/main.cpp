#include <iostream>
/*#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct date
{
   int y;
   int m;
   int d;
};

int is_leap(int y)
{
   return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}

int days_to_year_start(const date& d)
{
   int num_days = 0;
   for (int y = 1; y <= d.y; ++y)
   {

   }
   return 0;
}

int count_days_between(const date& d1, const date& d2)
{

   return 0;
}

*/

/*
#include <iostream>

using namespace std;

class Shape
{
   virtual int GetArea() = 0;
};

class Rectangle : public Shape
{
   int height;
   int width;
public:
   Rectangle(int height, int width)
   : height(height)
   , width(width)
   {
   }
   int GetArea() override
   {
      return height * width;
   }
};

class Triangle : public Shape
{
   int height;
   int width;
public:
   Triangle(int height, int width)
   : height(height)
   , width(width)
   {
   }
   int GetArea() override
   {
      return (height * width) / 2;
   }
};

class Circle : public Shape
{
   const double PI = 3.14;
   int radius;
public:
   Circle(int radius)
   : radius(radius)
   {
   }
   int GetArea() override
   {
      return std::round(PI * radius * radius);
   }
};


int main()
{

   Rectangle r(4, 3);
   cout << r.GetArea() << endl;
   Triangle t(5, 2);
   cout << t.GetArea() << endl;
   Circle c(5);
   cout << c.GetArea() << endl;
   return 0;
}

*/
/*
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person
{
   string Name = "Unkown";

   typedef pair<string, string> Trait;
   vector<Trait> Traits;
};

Person ConvertRawInputToPerson(string rawInput)
{
   Person person;
   vector<string> traits = split(rawInput, ' ');
   for (string trait : traits)
   {
      vector<string> keyValuePair = split(trait, '=');

      string key = keyValuePair[0];
      string value = keyValuePair[1];

      if (key == "Name") { person.Name == value; }
      else { person.Traits.push_back(make_pair(key, value)); }
   }
   return person;
}

bool StringEquals(string left, string right)
{
   for (int i = 0; i < left.length(); ++i)
   {
      if (left[i] != right[i]) { return false; }
   }
   return true;
}

bool HasTrait(vector<Person::Trait> & traits, Person::Trait & soughtTrait)
{
   return find_if(traits.begin(), traits.end(),
      [soughtTrait](Person::Trait & trait)
   {
      return StringEquals(soughtTrait.first, trait.first) && StringEquals(soughtTrait.second, trait.second);
   })
      != traits.end();
}

class Registry
{
   std::vector<Person> mPersons;

public:
   void Add(Person person)
   {
      mPersons.push_back(person);
   }

   Person FindMatchingPersonByRawTraits(string rawTraits)
   {
      Person soughtPerson;

      vector<string> traits = split(rawTraits, ' ');
      for (string trait : traits)
      {
         vector<string> keyValuePair = split(trait, '=');

         string key = keyValuePair[0];
         string value = keyValuePair[0];

         soughtPerson.Traits.push_back(make_pair(key, value));
      }

      for (Person & person : mPersons)
      {
         for (auto & soughtTrait : soughtPerson.Traits)
         {
            if (HasTrait(person.Traits, soughtTrait))
            {
               return person;
            }
         }
      }

      static Person unknownPerson;
      return unknownPerson;
   }
};

// Entry point
string GetNameFromRegistryByTraits(vector<string> rawRegistry, string soughtTraits)
{
   Registry registry;
   for (string rawInput : rawRegistry)
   {
      registry.Add(ConvertRawInputToPerson(rawInput));
   }

   Person person = registry.FindMatchingPersonByRawTraits(soughtTraits);
   return person.Name;
}

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

vector<string> split(const string& rawInput, char delimiter)
{
   std::stringstream ss(rawInput);
   std::vector<std::string> elems;
   std::string item;
   while (std::getline(ss, item, delimiter)) {
      elems.push_back(item);
   }
   return elems;
}

const string BAD_PERSON_NAME = "Error";

struct Person
{
   string Name = "Unknown";

   typedef pair<string, string> Trait;
   vector<Trait> Traits;
};

Person ConvertRawInputToPerson(string rawInput)
{
   Person person;
   vector<string> traits = split(rawInput, ' ');
   for (string trait : traits)
   {
      vector<string> keyValuePair = split(trait, '=');

      if (keyValuePair.size() != 2)
      {
         Person badPerson;
         badPerson.Name = BAD_PERSON_NAME;
         return badPerson;
      }

      string key = keyValuePair[0];
      string value = keyValuePair[1];

      if (key == "Name")
      {
         person.Name = value;
      }
      else
      {
         person.Traits.push_back(make_pair(key, value));
      }
   }
   return person;
}

bool HasTrait(vector<Person::Trait> & traits, Person::Trait & soughtTrait)
{
   return find(traits.begin(), traits.end(), soughtTrait) != traits.end();
}

class Registry
{
   std::vector<Person> mPersons;

public:
   void Add(Person person)
   {
      mPersons.push_back(person);
   }

   Person FindMatchingPersonByRawTraits(string rawTraits)
   {
      Person soughtPerson;

      vector<string> traits = split(rawTraits, ' ');
      for (string trait : traits)
      {
         vector<string> keyValuePair = split(trait, '=');

         string key = keyValuePair[0];
         string value = keyValuePair[1];

         soughtPerson.Traits.push_back(make_pair(key, value));
      }

      for (Person & person : mPersons)
      {
         bool matches = true;
         for (auto & soughtTrait : soughtPerson.Traits)
         {
            if (soughtTrait.first == "Name")
            {
               if (person.Name != soughtTrait.second)
               {
                  matches = false;
                  break;
               }
            }
            else if (!HasTrait(person.Traits, soughtTrait))
            {
               matches = false;
               break;
            }
         }
         if (matches == true)
         {
            return person;
         }
      }

      static Person unknownPerson;
      return unknownPerson;
   }
};

// Entry point
string GetNameFromRegistryByTraits(vector<string> rawRegistry, string soughtTraits)
{
   Registry registry;
   for (string rawInput : rawRegistry)
   {
      auto person = ConvertRawInputToPerson(rawInput);
      if (person.Name == BAD_PERSON_NAME)
      {
         return BAD_PERSON_NAME;
      }
      registry.Add(person);
   }

   Person person = registry.FindMatchingPersonByRawTraits(soughtTraits);
   return person.Name;
}

int main()
{
   vector<string> registry{
      "Name=John Sex=Man Age=46 Country=UK",
      "Name=Anita Sex=Woman Age=22 Country=NL",
      "Name=Keiko Sex=Woman Age=37 Country=JP",
      "Name=Denny Sex=Man Age=13 Country=NL",
      "Name=Mirjam Sex=Woman Age=28 Country=BE",
      "Name=Johnny Sex=Man Age=8 Country=UK",
      "Name=Anna Sex=Woman Age=71 Country=SW",
      "Name=Fred Sex=Man Age=51 Country=NL",
      "Name=Frederique Sex=Woman Age=51 Country=FR",
      "Name=Rob Sex=Man Age=42 Country=US",
      "Name=Robin Sex=Man Age=46 Country=US",
      "Name=Magda Sex=Woman Age=29 Country=PL",
      "Name=Peter Sex=Man Age=66 Country=RU",
      "Name=Pete Sex=Man Age=66 Country=US",
      "Name=Xiaoling Sex=Woman Age=26 Country=CH",
   };

   cout << GetNameFromRegistryByTraits(registry, "Name=Xiaoling");
   return 0;
}
*/


#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <map>
#include <set>
#include <exception>

using namespace std;

class ex_more_than_two_children : public exception
{
};

class ex_duplicate_pair : public exception
{
};


template <class T>
class Tree 
{
   // Store tree as graph - it is a good structure to search cycles using simple DFS
   int v; // num vertices
   map<T, set<T>> adj;
   map<T, bool> visited;
   map<T, bool> cyclic;

   bool hasCycleVertex(T v)
   {
      if (visited[v] == false)
      {
         visited[v] = true;
         cyclic[v] = true;
         for (auto vi : adj[v])
         {
            if (!visited[vi] && hasCycleVertex(vi))
            {
               return true;
            }
            else if (cyclic[vi])
            {
               return true;
            }
         }
      }
      cyclic[v] = false;
      return false;
   }

   void dfs(T v)
   {
      if (visited[v] == false)
      {
         cout << '(' << v;
         visited[v] = true;
         for (auto vi : adj[v])
         {
            if (!visited[vi])
            {
               dfs(vi);
            }
         }
         cout << ')';
      }
   }


public:
   Tree(int v) : v(v) {}
   void AddEdge(T v, T w)
   {
      if (adj[v].count(w) != 0)
      {
         throw ex_duplicate_pair();
      }
      if (adj[v].size() == 2) // we're trying to add more than 2 children
      {
         throw ex_more_than_two_children();
      }
      adj[v].insert(w);
      visited[v] = false;
      cyclic[v] = false;
   }
   bool HasCycle()
   {
      for (auto& kv : adj)
      {
         if (hasCycleVertex(kv.first))
         {
            return true;
         }
      }
      return false;
   }

   void Traverse()
   {
      for (auto& vi : visited)
      {
         vi.second = false;
      }
      T v = adj.begin()->first;
      dfs(v);
      cout << endl;
   }

   bool HasMultipleRoots()
   {
      // Gather vertices which have no incoming edges and if there are more than one report this
      map<T, int> vertex_to_num_incoming;
      for (auto& a : adj)
      {
         for (auto& v : a.second)
         {
            vertex_to_num_incoming[v]++;
         }
      }
      return adj.size() - vertex_to_num_incoming.size() > 1;
   }
};

vector<string> Split(const string& rawInput, char delimiter)
{
   std::stringstream ss(rawInput);
   std::vector<std::string> elems;
   std::string item;
   while (std::getline(ss, item, delimiter)) 
   {
      elems.push_back(item);
   }
   return elems;
}

const string E1 = "E1"; // Invalid input format
const string E2 = "E2"; // Duplicate pair
const string E3 = "E3"; // Parent has more than two children
const string E4 = "E4"; // Tree contains cycle
const string E5 = "E5"; // Multiple roots

bool ValidInput(vector<string> edges)
{
   if (edges.empty())
   {
      return false;
   }
   // TODO: Implement additional checks
   
   return true;
}



int main()
{
   string input;

   // TODO: stub for quick testing
   // istream& is = istringstream("(A,B) (B,D) (B,E) (A,C)");
   // getline(is, input);

   istream& is = cin;
   
   getline(is, input);
   vector<string> edges = Split(input, ' ');
   
   if (!ValidInput(edges))
   {
      cout << E1 << endl;
      return -1;
   }

   Tree<char> t(edges.size());

   try
   {
      for (auto& edge : edges)
      {
         t.AddEdge(edge[1], edge[3]);
      }
   }
   catch (ex_duplicate_pair&)
   {
      cout << E2 << endl;
      return -2;
   }
   catch (ex_more_than_two_children&)
   {
      cout << E3 << endl;
      return -3;
   }

   if (t.HasCycle())
   {
      cout << E4 << endl;
      return -4;
   }

   if (t.HasMultipleRoots())
   {
      cout << E5 << endl;
      return -5;
   }

   t.Traverse();

   return 0;
}
