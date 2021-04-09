#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &input)
{
	printf("input addr = %x\n", &input);
	int len = input.size();
	int tmp = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len - 1; j++) {
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
	//如果这个地方报错是由于你的g++ 不支持C++11
	vector<int> b{1,5,2,2,3,7,9};
	quickSort(b);
	for (vector<int>::iterator itr = b.begin(); itr != b.end(); itr++) {
		cout << *itr << endl;
	}
	return 0;
}
