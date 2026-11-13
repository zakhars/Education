#include <iostream>

using namespace std;

void print_array(int* a, int n)
{
	for (int i = 0; i < n; i++)	{ 
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	const int n = 10;

	int a[n] = { 3,1,2,6,5,3,8,1,8,3 };
	int uniqa[n];
	int uniqc[n];
	int un = 0;

	for (int i = 0; i < n; i++) {
		bool found = false;
		for (int j = 0; j < un; j++)
			if (a[i] == uniqa[j]) {
				uniqa[j] = a[i];
				uniqc[j]++;
				found = true;
				break;
			}
		if (!found) {
			uniqa[un] = a[i];
			uniqc[un] = 1;
			un++;
		}
	}

	cout << "Initial array" << endl;
	print_array(a, n);

	cout << "Unsorted unique array" << endl;
	print_array(uniqa, un);
	print_array(uniqc, un);

	for (int i = 0; i < un; i++) {
		for (int j = i; j < un; j++)
			if (uniqc[i] > uniqc[j]) {
				swap(uniqa[i], uniqa[j]);
				swap(uniqc[i], uniqc[j]);
			}
	}

	cout << "Sorted unique array" << endl;
	print_array(uniqa, un);
	print_array(uniqc, un);

	return 0;
}