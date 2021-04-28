#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &input)
{
	int len = input.size();
	int tmp = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (input[i] > input[j]) {
				tmp = input[i];
				input[i] = input[j];
				input[j] = tmp;
			}
		}
	}
	return;
}

int main()
{
	vector<int> b = {1,5,2,2,3,7,9};
	bubbleSort(b);
	for (vector<int>::iterator itr = b.begin(); itr != b.end(); itr++) {
		cout << *itr << endl;
	}
	return 0;
}

