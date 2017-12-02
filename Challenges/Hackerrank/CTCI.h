#pragma once
#include <algorithm>
#include <vector>
#include <functional>
#include <limits>
#include <iterator>
#include <stack>
#include <queue>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

#undef lst1
#undef lst2

namespace hrnk
{
using namespace std;

namespace ctci // Cracking the Code Interview tasks
{

// Arrays: Left Rotation
// https://www.hackerrank.com/challenges/ctci-array-left-rotation
namespace array_left_rotation
{
   void rotate_one(std::vector<int>& v, size_t sz)
   {
      int v0 = v[0];
      memmove(&v[0], &v[1], (sz-1)*sizeof(int));
      v[sz-1] = v0;
   }

   auto solution = [](std::vector<int>& v, int k)
   {
      const size_t sz = v.size();
      if (sz > 1)
      {
         for (size_t i = 0; i < k % sz; i++) rotate_one(v, sz);
      }
   };

   // Author's solution
   auto solution_orig = [](std::vector<int>& v, int d)
   {
      // Because the constraints state d < n, we need not concern ourselves with shifting > n units.
      size_t n = v.size();

      // Create new array for rotated elements:
      vector<int> rotated(n);

      // Copy segments of shifted elements to rotated array:
      memcpy(&rotated[0], &v[d], (n-d)*sizeof(int));
      memcpy(&rotated[n-d], &v[0], d*sizeof(int));

      v = rotated;
   };

   template<typename Solution>
   void run(Solution solution, bool output = true)
   {
      istream& input = istringstream("5 4\n1 2 3 4 5");
      //istream& input = cin;

      int n, k;
      input >> n >> k;
      vector<int> v(n);
      copy_n(istream_iterator<int>(input), n, std::begin(v));

      solution(v, k);

      if (output) copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
   }
} // array_left_rotation

// Strings: Making Anagrams
// https://www.hackerrank.com/challenges/ctci-making-anagrams
namespace anagrams
{
   auto solution = [](string a, string b)
   {
      int num_deletions = 0;
      string b2;
      size_t bsz = b.size();
      for (auto c : a)
      {
         size_t pos;
         if ((pos = b.find(c)) == string::npos)
         {
            num_deletions++;
         }
         else
         {
            b2 += b[pos];
            b.erase(pos, 1);
         }
      }
      return num_deletions + bsz - b2.size();
      // Another approach is to use set_intersection
   };


   // Author's solution
   auto solution_orig = [](string a, string b)
   {
      int A[26] = {0};
      int B[26] = {0};
      for(size_t i = 0; i < a.length(); i++)
         A[(a[i] - 'a')]++;
      for(size_t i = 0; i < b.length(); i++)
         B[(b[i] - 'a')]++;
      int outp = 0;
      for(size_t i=0; i < 26; i++)
      {
         outp = outp + A[i] + B[i] - 2*min(A[i],B[i]);
      }
      return outp;
   };

   template<typename Solution>
   void run(Solution solution, bool output = true)
   {
      istream& input = istringstream("cde\n abc\n");
      //istream& input = cin;

      string a, b;
      input >> a >> b;
      size_t n = solution(a, b);

      if (output) cout << n << endl;
   }

} // anagrams

// HashTables: Ransom Note
// https://www.hackerrank.com/challenges/ctci-ransom-note
namespace rn
{
   bool ransom_note(vector<string> magazine, vector<string> ransom)
   {
      if (magazine.size() < ransom.size()) return false;
      unordered_multiset<string> dict(begin(magazine), end(magazine));
      for (auto& r : ransom)
      {
         auto it = dict.find(r);
         if (it == dict.end())
         {
            return false;
         }
         dict.erase(it); // remove only one element
      }
      return true;
   }

   int run()
   {
      istream& input = istringstream(
         "6 4\n"
         "give me one grand today night\n"
         "give one grand today\n");
      //istream& input = cin;

      int m, n;
      input >> m >> n;
      vector<string> magazine(m);
      copy_n(istream_iterator<string>(input), m, begin(magazine));
      input.ignore();
      vector<string> ransom(n);
      copy_n(istream_iterator<string>(input), n, begin(ransom));

      cout << (ransom_note(magazine, ransom) ? "Yes" : "No") << endl;
           
      return 0;
   }
} // rn

// Linked Lists: Detect a Cycle
// https://www.hackerrank.com/challenges/ctci-linked-list-cycle
namespace dc
{
   struct Node 
   {
      int data;
      struct Node* next;
   };

   bool has_cycle(Node* head) 
   {
       Node* slow = head;
       Node* fast = head;
       while(true)
       {
           if (slow == nullptr) return false;
           if (fast == nullptr || fast->next == nullptr) return false;
           slow = slow->next;
           fast = fast->next->next;
           if (slow == fast) return true;
       }
   }

   int run()
   {
      Node* lst1 = new Node();
      lst1->next = nullptr;

      Node* lst2 = new Node();
      lst2->next = new Node();
      lst2->next->next = new Node();
      lst2->next->next->next = lst2->next; //loop

      cout << has_cycle(lst1) << endl;
      cout << has_cycle(lst2) << endl;
           
      return 0;
   }
} // dc

// Stacks: Balanced Brackets
// https://www.hackerrank.com/challenges/ctci-balanced-brackets
namespace bb
{
   inline bool is_opening(char br) 
   { 
       return br == '(' || br == '{' || br == '[';
   }

   inline bool is_matched(char bo, char bc) 
   { 
       return bo == '(' && bc == ')' || 
              bo == '[' && bc == ']' ||
              bo == '{' && bc == '}';
   }

   bool is_balanced(string expression) 
   {
       stack<char> brackets;
       for(char br : expression)
       {
           if(is_opening(br))
           {
               brackets.push(br);
           }
           else
           {
               if (brackets.empty() || !is_matched(brackets.top(), br))
               {
                   return false;
               }
               brackets.pop();
           }
       }
       return brackets.empty();
   }

   int run()
   {
      istream& input = istringstream(
         "3\n"
         "{[()]}\n"
         "{[(])}\n"
         "{{[[(())]]}}\n");

      //istream& input = cin;

      int t;
      input >> t;
      for(int i = 0; i < t; i++)
      {
         string expression;
         input >> expression;
         bool answer = is_balanced(expression);
         cout << (answer ? "YES" : "NO") << endl;
      }
      return 0;
   }
} // bb

// Queues: A Tale of Two Stacks
// https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks
namespace ts
{
   class MyQueue
   {
      stack<int> stack_newest_on_top;
      stack<int> stack_oldest_on_top;

      void newest_to_oldest()
      {
         while (!stack_newest_on_top.empty())
         {
            stack_oldest_on_top.push(stack_newest_on_top.top());
            stack_newest_on_top.pop();
         }
      }
      void oldest_to_newest()
      {
         while (!stack_oldest_on_top.empty())
         {
            stack_newest_on_top.push(stack_oldest_on_top.top());
            stack_oldest_on_top.pop();
         }
      }

   public:

      void push(int x)
      {
         stack_newest_on_top.push(x);
      }

      void pop()
      {
         if(stack_oldest_on_top.empty()) newest_to_oldest();
         stack_oldest_on_top.pop();
      }

      int front()
      {
         if(stack_oldest_on_top.empty()) newest_to_oldest();
         return stack_oldest_on_top.top();
      }
   };

   int run()
   {
      istream& input = istringstream(
         "10\n"
         "1 42\n"
         "2\n"
         "1 14\n"
         "3\n"
         "1 28\n"
         "3\n"
         "1 60\n"
         "1 78\n"
         "2\n"
         "2\n");

      //istream& input = cin;
      //ifstream& input = ifstream("D:\\Code\\C++ Examples\\x64\\Debug\\data.txt");

      MyQueue q1;
      int q, type, x;
      input >> q;

      for (int i = 0; i < q; i++)
      {
         input >> type;
         switch (type)
         {
         case 1:
            input >> x;
            q1.push(x);
            break;
         case 2:
            q1.pop();
            break;
         default:
            cout << q1.front() << endl;
            break;
         }
      }
      return 0;
   }
} // ts

// Trees: Is This a Binary Search Tree?
// https://www.hackerrank.com/challenges/ctci-is-binary-search-tree
namespace bs
{
   struct Node 
   {
      int data;
      Node* left = nullptr;
      Node* right = nullptr;
      explicit Node(int d) : data(d) {}
   };

   bool isSorted(const vector<int>& v)
   {
       for(size_t k = 1; k < v.size(); k++)
       {
           if (v[k] <= v[k-1]) return false;
       }
       return true;
   }

   bool checkBST(Node* root) 
   {
       static vector<int> values;
       if (root == nullptr) return true;
       checkBST(root->left);
       values.push_back(root->data);
       checkBST(root->right);
       return isSorted(values);
   }

   int run()
   {

      //            4
      //           / \
      //          2   6  
      //        / \   / \ 
      //       1   3 5   7

      Node* tree = new Node(4);
      tree->left = new Node(2);
      tree->right = new Node(6);

      tree->left->left = new Node(1);
      tree->left->right = new Node(3);

      tree->right->left = new Node(5);
      tree->right->right = new Node(7);

      cout << (checkBST(tree) ? "YES" : "NO") << endl;

      return 0;
   }
} // bs

// Heaps: Find the Running Median
// https://www.hackerrank.com/challenges/ctci-find-the-running-median
namespace rm
{
	template <typename T> class running_median
	{
		priority_queue<T, vector<T>, less<T>> max_heap;
		priority_queue<T, vector<T>, greater_equal<T>> min_heap;
	public:
		void push(T val)
		{
			if (max_heap.empty() || val < max_heap.top())
			{
				max_heap.push(val);
			}
			else
			{
				min_heap.push(val);
			}

			if (max_heap.size() - min_heap.size() == 2)
			{
				T v = max_heap.top();
				min_heap.push(v);
				max_heap.pop();
			}
			else if (min_heap.size() - max_heap.size() == 2)
			{
				T v = min_heap.top();
				max_heap.push(v);
				min_heap.pop();
			}
		}

		T median()
		{
			if (min_heap.size() == max_heap.size())
			{
				return (max_heap.top() + min_heap.top()) / 2.0;
			}
			return max_heap.size() < min_heap.size() ? min_heap.top() : max_heap.top();
		}
	};


   int run()
   {
      istream& input = istringstream(
         "6\n"
         "12\n"
         "4\n"
         "5\n"
         "3\n"
         "8\n"
         "7\n");

      //istream& input = cin;

      int n;
      input >> n;
      double val;
      running_median<double> rm;
      for(int i = 0; i < n; i++)
      {
         input >> val;
         rm.push(val);
         cout.setf(ios::fixed);
         cout << setprecision(1) << rm.median() << endl;
      }
      return 0;
   }
} // rm

// Tries: Contacts
// https://www.hackerrank.com/challenges/ctci-contacts
namespace fp
{
	class notebook
	{
      class Node
      {
         unordered_map<char, Node*> m_children;
         int m_numWordsBelow = 0;

      public:

         void IncNumWords() 
         { 
            m_numWordsBelow++; 
         }
         
         int GetNumWords() const
         { 
            return m_numWordsBelow; 
         }

         Node* GetChild(char ch)
         {
            auto node = m_children.find(ch);
            return (node == m_children.end() ? nullptr : node->second);
         }
         
         Node* AddChild(char ch)
         {
            Node* newNode = new Node();
            m_children.insert(make_pair(ch, newNode));
            newNode->IncNumWords();
            return newNode;
         }
      };

		ostream& output;
      Node* trie = nullptr;

      void add_word(const string& word)
      {
         Node* cur = trie;
         size_t i = 0;
         for(; i < word.length(); ++i)
         {
            auto node = cur->GetChild(word[i]);
            if(node == nullptr)
            {
               break;
            }
            cur = node;
            cur->IncNumWords();
         }

         for(; i < word.length(); ++i)
         {
            cur = cur->AddChild(word[i]);
         }
      }

      size_t get_pattern_count(const string& pattern)
      {
         Node* cur = trie;
         for(size_t i = 0; i < pattern.length(); ++i)
         {
            auto node = cur->GetChild(pattern[i]);
            if(node == nullptr)
            {
               return 0;
            }
            cur = node;
         }

         return cur->GetNumWords();
      }

   public:

		notebook(ostream& o) : output(o) 
      {
         trie = new Node();
      }

      void execute(const string& command)
		{
			if (command.length() > 5 && command.substr(0, 5) == "find ")
			{
				string pattern = command.substr(5);
            output << get_pattern_count(pattern) << endl;
			}
			else if (command.length() > 4 && command.substr(0, 4) == "add ")
			{
				string word = command.substr(4);
            add_word(word);
			}
         else
         {
            output << "Bad string: " << command << endl;
         }
		}
	};


	int run()
	{
      // ifstream& input = ifstream("D:\\Code\\C++ Examples\\x64\\Debug\\data.txt");

      istream& input = istringstream(
			"4\n"
			"add hack\n"
			"add hackerrank\n"
			"find hac\n"
			"find hak"
		);


		//istream& input = cin;

		int n;
		input >> n;
      input.ignore();
		notebook nb(cout);
		for (int i = 0; i < n; i++)
		{
			string command;
			getline(input, command);
			nb.execute(command);
		}
		return 0;
	}
} // fp

// Sorting: Bubble Sort
// https://www.hackerrank.com/challenges/ctci-bubble-sort
namespace bbs
{
   unsigned bubble_sort(vector<int>& v)
   {
      unsigned numSwaps = 0;
      const size_t n = v.size();

      for (unsigned i = 0; i < n; i++)
      {
         bool bSwaped = false;
         for (size_t j = n - 1; j > i; j--)
         {
            if (v[j] < v[j - 1])
            {
               swap(v[j], v[j - 1]);
               numSwaps++;
               bSwaped = true;
            }
         }
         if(!bSwaped) 
         {
            break;
         }
      }

      return numSwaps;
   }

   int run()
   {
      istream& input = istringstream(
         "5\n"
         "1 3 2 4 5");

      //istream& input = cin;

      int n;
      input >> n;
      std::vector<int> v(n);
      std::copy_n(std::istream_iterator<int>(input), n, std::begin(v));

      unsigned  numSwaps = bubble_sort(v);
      cout << "Array is sorted in " << numSwaps << " swaps." << std::endl;
      cout << "First Element: " << *v.begin() << endl;
      cout << "Last Element: " << *(v.end() - 1) << endl;

      return 0;
   }
} // bbs

// Sorting: Comparator
// https://www.hackerrank.com/challenges/ctci-comparator-sorting
namespace qs
{
   struct Player 
   {
      string name;
      int score;
   }; 

   vector<Player> comparator(const vector<Player>& players)
   {
      vector<Player> sorted = players;
      sort(begin(sorted), end(sorted), 
         [](Player& p1, Player& p2) 
         { 
            if (p1.score > p2.score) return true; 
            if (p1.score == p2.score) return p1.name < p2.name; 
            return false;
         });
      return sorted;
   }

   int run()
   {
      istream& input = istringstream(
         "5\n"
         "amy 100\n"
         "david 100\n"
         "heraldo 50\n"
         "aakansha 75\n"
         "aleksa 150");

      //istream& input = cin;

      int n;
      input >> n;
      vector<Player> players;

      string name;
      int score;
      for(int i = 0; i < n; i++)
      {
         input >> name >> score;
         Player p { name, score };
         players.push_back(p);
      }
    
      vector<Player> answer = comparator(players);
      for(size_t i = 0; i < answer.size(); i++) 
      {
         cout << answer[i].name << " " << answer[i].score << endl;
      }

      return 0;
   }
} // qs

// Binary Search: Ice Cream Parlor
// https://www.hackerrank.com/challenges/ctci-ice-cream-parlor
namespace bsr
{
   class IceCream 
   {
   public: 
      int cost; 
      int index;

      IceCream(int cost = -1, int index = -1) :
         cost(cost), index(index)
      {
      }

      bool operator<(const IceCream& other) const { return cost < other.cost; }
   };
    
   int binarySearch(int l, int r, const vector<IceCream>& arr, int val) 
   {
      while (l < r)
      {
         int m = l + (r - l) / 2 + 1;
         if (val < arr[m].cost)
            return binarySearch(l, m - 1, arr, val);
         else
            return binarySearch(m, r, arr, val);
      }
      return (arr[l].cost == val) ? arr[l].index : -1;
   }

   int run()
   {

      //istream& input = ifstream(R"(d:\data.txt)");

      istream& input = istringstream(
         "2\n"
         "4\n"
         "5\n"
         "1 4 5 3 2\n"
         "4\n"
         "4\n"
         "2 2 4 3");

      //istream& input = cin;

      int t;
      int n, m;
      input >> t;
      for (int test = 0; test < t; test++) 
      {
         input >> m >> n;
         vector<IceCream> arr(n);

         for (int i = 0; i < n; i++) 
         {
            int cost;
            input >> cost;
            arr.push_back(IceCream(cost, i + 1));
         }

         stable_sort(arr.begin(), arr.end());

         int firstIndex = 100000, secondIndex = 100000;
         for (int i = 0; i < n - 1; i++) 
         {
            int search = m - arr[i].cost;
            if (search >= arr[i].cost)
            {
               int index = binarySearch(i + 1, n - 1, arr, search);
               if (index != -1)
               {
                  cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                  break;
               }
            }
         }
      }
      return 0;
   }

} // bsr

// Merge Sort: Counting Inversions
// https://www.hackerrank.com/challenges/ctci-merge-sort
namespace ms
{

   void merge(size_t l, size_t m, size_t r, vector<int>& arr, vector<int>& buf, size_t& count_inversions)
   {
      size_t bi = l;
      size_t li = l; 
      size_t ri = m + 1;
      while (li <= m && ri <= r)
      {
         if (arr[li] <= arr[ri])
         {
            buf[bi++] = arr[li++];
         }
         else
         {
            buf[bi++] = arr[ri++];
            count_inversions += (m - li + 1);
         }
      }
      while (li <= m)
      {
         buf[bi++] = arr[li++];
      }
      while (ri <= r)
      {
         buf[bi++] = arr[ri++];
      }
      for (size_t i = l; i <= r; i++)
      {
         arr[i] = buf[i];
      }
   }

   size_t merge_sort(size_t l, size_t r, vector<int>& arr, size_t& count_inversions, vector<int>& buf)
   {
      if (l < r)
      {
         size_t m = (l + r) / 2; // or [l + (r - l) / 2], to avoid overflow
         merge_sort(l, m, arr, count_inversions, buf);
         merge_sort(m + 1, r, arr, count_inversions, buf);
         merge(l, m, r, arr, buf, count_inversions);
      }
      return count_inversions;
   }

   int run()
   {
      istream& input = ifstream(R"(d:\data.txt)");
      
      /*istream& input = istringstream(
         "2\n"
         "5\n" 
         "1 1 1 2 2\n"
         "5\n"
         "2 1 3 1 2\n");*/

      //istream& input = cin;

      int t;
      input >> t;

      for (int i = 0; i < t; i++) 
      {
         int n;
         input >> n; 
         vector<int> arr(n);
         copy_n(istream_iterator<int>(input), n, begin(arr));
         size_t count_inversions = 0;
         vector<int> buf(n);
         cout << merge_sort(0, arr.size()-1, arr, count_inversions, buf) << endl;
      } 
      return 0;
   }

} // ms

// DFS: Connected Cell in a Grid
// https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid
namespace dfs
{
   vector<pair<int,int>> visited;

   bool isVisited(pair<int,int> point)
   {
      return find(begin(visited), end(visited), point) != end(visited);
   }

   bool isValid(pair<int,int> point, const vector<vector<int>>& grid)
   {
      return point.first >= 0 && 
             point.second >= 0 && 
             point.first < static_cast<int>(grid.size()) && 
             point.second < static_cast<int>(grid[0].size());
   }

   int get_region_size(pair<int,int> initial_point, const vector<vector<int>>& grid)
   {
      int row = initial_point.first;
      int col = initial_point.second;

      if (isVisited(initial_point) || !isValid(initial_point, grid) || grid[row][col] == 0) return 0;
      visited.push_back(initial_point);

      auto p1 = make_pair(row + 1, col);
      auto p2 = make_pair(row + 1, col + 1);
      auto p3 = make_pair(row + 1, col - 1);
      auto p4 = make_pair(row, col - 1);
      auto p5 = make_pair(row, col + 1);
      auto p6 = make_pair(row - 1, col);
      auto p7 = make_pair(row - 1, col + 1);
      auto p8 = make_pair(row - 1, col - 1);

      return 1 + get_region_size(p1, grid)
               + get_region_size(p2, grid)
               + get_region_size(p3, grid)
               + get_region_size(p4, grid)
               + get_region_size(p5, grid)
               + get_region_size(p6, grid)
               + get_region_size(p7, grid)
               + get_region_size(p8, grid);      
   }

   int get_biggest_region(const vector<vector<int>>& grid) 
   {
      vector<int> region_sizes;
      for(size_t row = 0; row < grid.size(); row++)
         for(size_t col = 0; col < grid[0].size(); col++)
            if(grid[row][col] == 1 && !isVisited(make_pair(row, col)))
               region_sizes.push_back(get_region_size(make_pair(row, col), grid));
      if(region_sizes.empty()) return 0;
      return *max_element(begin(region_sizes), end(region_sizes));
   }

   int run()
   {
      istream& input = istringstream(
         "4\n"
         "4\n"
         "1 1 0 0\n"
         "0 1 1 0\n"
         "0 1 1 0\n"
         "1 0 0 0\n");

      //istream& input = cin;

      int n, m;
      input >> n >> m;
      vector<vector<int>> grid(n, vector<int>(m));
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            input >> grid[i][j];
         }
      }
      cout << get_biggest_region(grid) << endl;
      return 0;
   }
} // dfs

// BFS: Shortest Reach in a Graph
// https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach
namespace bfs
{
   class Graph {
   public:

      explicit Graph(int n) {
         adjacents.resize(n);
      }

      void AddEdge(int u, int v) {
         adjacents[u].insert(v);
         adjacents[v].insert(u);
      }

      vector<int> ShortestReach(size_t v) {
         vector<int> distances(adjacents.size(), -1);
         visited.clear();
         bfs(v, distances);
         return move(distances);
      }
   private:

      bool isVisited(size_t v) {
         return visited.count(v) != 0;
      }

      void bfs(size_t v, vector<int>& distances) {
         queue<size_t> vqueue;
         vqueue.push(v);
         visited.insert(v);
         distances[v] = 0;
         while (!vqueue.empty()) {
            size_t vi = vqueue.front();
            vqueue.pop();
            for(auto u : adjacents[vi]) {
               if (!isVisited(u)) {
                  distances[u] = distances[vi] + weight;
                  visited.insert(u);
                  vqueue.push(u);
               }
            }
         }
      }

      vector<set<size_t>> adjacents;
      set<size_t> visited;
      const int weight = 6;
   };

   int run() 
   {
      //istream& input = ifstream(R"(d:\data.txt)");
      istream& input = istringstream(
         "1\n"
         "10 9\n"
         "1 2\n"
         "1 3\n"
         "2 5\n"
         "3 4\n"
         "3 9\n"
         "4 9\n"
         "5 6\n"
         "6 7\n"
         "6 8\n"
         "1\n");

      //istream& input = cin;
      
      int queries;
      input >> queries;

      for (int q = 0; q < queries; ++q) 
      {
         int n, m;
         input >> n;
         // create a graph of size n
         Graph graph(n);
         input >> m;
         // read and set edges
         for (int i = 0; i < m; ++i) 
         {
            int u, v;
            input >> u >> v;
            --u; --v;
            // add each edge to the graph
            graph.AddEdge(u, v);
         }
         size_t vstart;
         input >> vstart;
         --vstart;

         // find shortest reach from node s
         vector<int> distances = graph.ShortestReach(vstart);

         for (size_t i = 0; i < distances.size(); i++)
         {
            if (i != vstart)
            {
               cout << distances[i] << " ";
            }
         }
         cout << endl;
      }

      return 0;
   }

} // bfs

// Time Complexity: Primality
// https://www.hackerrank.com/challenges/ctci-big-o
namespace pn
{
   bool IsPrime(int n)
   {
      if (n <= 1) return false;
      if (n <= 3) return true;
      if (n % 2 == 0 || n % 3 == 0) return false;
      for (int i = 5; i * i <= n; i += 6) {
         if (n % i == 0 || n % (i + 2) == 0) return false;
      }
      return true;
   }

   int run() 
   {
      istream& input = istringstream(
         "3\n"
         "1\n"
         "2\n"
         "7\n");

      //istream& input = cin;
      
      int count;
      input >> count;

      for (int i = 0; i < count; ++i) 
      {
         int n;
         input >> n;
         cout << (IsPrime(n) ? "Prime" : "Not prime") << endl;
      }

      return 0;
   }

} // pn

// Recursion: Davis' Staircase
// https://www.hackerrank.com/challenges/ctci-recursive-staircase
namespace ds
{

   int getNumWays(int h, vector<int>& precalc) 
   {
      if (h < 0) return 0;

      if (precalc[h] == 0)
      {
         precalc[h] = getNumWays(h - 1, precalc) + getNumWays(h - 2, precalc) + getNumWays(h - 3, precalc);
      }
      return precalc[h];
   }

   int GetNumWays(int height) {
      if (height < 0) return 0;
      vector<int> precalc(height + 1);
      precalc[0] = 1;
      return getNumWays(height, precalc);
   }
    
   int run() 
   {
      istream& input = istringstream(
         "1\n"
         "4\n");

      //istream& input = cin;
      
      int numStaircases;
      input >> numStaircases;

      for (int i = 0; i < numStaircases; ++i) 
      {
         int height;
         input >> height;
         cout << GetNumWays(height) << endl;
      }

      return 0;
   }

} // pn

  // DP: Coin Change
  // https://www.hackerrank.com/challenges/ctci-coin-change
namespace dpc
{

   long long make_change(const vector<int>& coins, int money) 
   {
      if (money < 0 || coins.empty()) {
         return 0;
      }

      vector<long long> num_ways(money + 1, 0);
      num_ways[0] = 1;

      for (auto coin : coins) {
         for(int amount = 1; amount <= money; ++amount) {
            if (coin <= amount) {
               num_ways[amount] += num_ways[amount-coin];
            }
         }
      }
      return num_ways[money];
   }

   int run()
   {
      istream& input = istringstream(
         "12 3\n"
         "1 2 5\n"
      );

      //istream& input = cin;

      int n, m;
      input >> n >> m;
      vector<int> coins(m);
      copy_n(istream_iterator<int>(input), m, begin(coins));
   
      cout << endl << make_change(coins, n) << endl;
      
      return 0;
   }

} // dpc

} // ctci
} // hrnk



