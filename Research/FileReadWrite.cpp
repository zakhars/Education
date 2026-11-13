#include <iostream>
#include <fstream>
#include <cstdio>
#include <chrono>


using namespace std;


void file_write_remove()
{
    remove("example.txt");
    fstream file("example.txt", ios::out);

    if (file.is_open())
    {
        file << "Hello, World!\n";
        file.close();
    }
    else {
        cout << "Failed to open file!\n";
    }

}


int main()
{
    for (int i = 0; i < 1000; i++)
    {
        auto begin = chrono::high_resolution_clock::now();

        file_write_remove();

        auto end = chrono::high_resolution_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns" << endl;
    }
}
