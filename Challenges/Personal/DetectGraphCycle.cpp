#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <class T>
class Graph
{
   int v; // num vertices
   map<T, vector<T>> adj;
   map<T, bool> visited;
   map<T, bool> cyclic;

   bool hasCycleVertex(T v, map<T, bool>& visited, map<T, bool>& cyclic)
   {
      if (visited[v] == false) 
      {
         visited[v] = true;
         cyclic[v] = true;
         for (auto vi : adj[v]) 
         {
            if (!visited[vi] && hasCycleVertex(vi, visited, cyclic)) 
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
public:
   Graph(int v) : v(v) {}
   void addEdge(T v, T w) 
   { 
      adj[v].push_back(w); 
      visited[v] = false;
      cyclic[v] = false;
   }
   bool HasCycle()
   {
      for (auto& kv : adj) 
      {
         if (hasCycleVertex(kv.first, visited, cyclic)) 
         {
            return true;
         }
      }
      return false;
   }
};


int main_dl()
{
   Graph<char> g(4);
   g.addEdge('A', 'B');
   g.addEdge('A', 'C');
   g.addEdge('B', 'C');
   g.addEdge('C', 'A');
   g.addEdge('C', 'D');
   g.addEdge('D', 'D');

   cout << g.HasCycle() << endl;
   return 0;
}
