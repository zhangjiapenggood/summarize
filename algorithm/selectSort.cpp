#include <iostream>
#include <vector>

using namespace std;

vector<int> selectSort(vector<int> inputValue)
{
    vector<int> ret;
    for(int i =0; i < inputValue.size(); i++){
        int minValue = inputValue[i];
        for(int j = i+1; j <inputValue.size(); j++){
            if(minValue > inputValue[j]){
                int tmp = inputValue[j];
                inputValue[j] = minValue;
                minValue = tmp;
            }
        }
        ret.push_back(minValue);
        cout << minValue << endl;
    }
    return ret;
}

int main()
{
    vector<int> tmp = {21,15,9,212,4123,1};
    selectSort(tmp);
    return 0;
}
