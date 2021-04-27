#include<iostream>
#include<string>
#include <vector>
using namespace std;
/*输入

a11b2bac3bad3abcd2

b2abcd2bac3bad3a11
abcd2b2bac3bad3a11

输出

abcdabcdbbbacbacbacbadbadbadaaaaaaaaaaa
*/


string uncompress(string compressStr)
{
    string ret;
    string tmpstr1;
    int tmpInt1 = 0;
    vector<string> tmpStr_vec;
    vector<int> tmpInt_vec;
    bool falg = false; //false代表字符 true 代表数字
    for (int i = 0; i < compressStr.length(); i++)
    {
      if (compressStr[i] >= 'a' && compressStr[i] <= 'z') {
          tmpstr1 += compressStr[i];
          if(!falg &&compressStr[i+1] >= '0' && compressStr[i+1] <= '9'){
              tmpStr_vec.push_back(tmpstr1);
              tmpstr1 = "";
              falg = true;
          }
      }
      else {
          tmpInt1 = tmpInt1 * 10 + (compressStr[i] - '0');
          cout << tmpInt1 <<endl;
          if(falg && compressStr[i+1] >= 'a' && compressStr[i+1] <= 'z'){
              tmpInt_vec.push_back(tmpInt1);
              tmpInt1 = 0;
              falg = false;
          }
          else if (compressStr[i+1] == '\0'){
              tmpInt_vec.push_back(tmpInt1);
              tmpInt1 = 0;
          }
      }
    }
    for(auto a : tmpStr_vec){
         cout << a <<endl;
    }

    for(auto b: tmpInt_vec){
        cout << b <<endl;
    }

    cout << "*******************************************" <<endl;
    for (int i =0; i <tmpInt_vec.size(); i++){
        for(int j= i+1; j < tmpInt_vec.size(); j++){
              if(tmpInt_vec[i] > tmpInt_vec[j]){
                  int inttmp = tmpInt_vec[i];
                  tmpInt_vec[i] = tmpInt_vec[j];
                  tmpInt_vec[j] = inttmp;
                  string strtmp = tmpStr_vec[i];
                  tmpStr_vec[i] = tmpStr_vec[j];
                  tmpStr_vec[j] = strtmp;
              }
             else if(tmpInt_vec[i] == tmpInt_vec[j]){
                 string tmp1str = tmpStr_vec[i];
                 string tmp2str = tmpStr_vec[j];
                 int k=0;
                 while(k < tmp1str.length() && k < tmp2str.length()){
                     if(tmp1str[k] > tmp2str[k]){
                         tmpStr_vec[i] = tmp2str;
                         tmpStr_vec[j] = tmp1str;
                         break;
                     }
                     k++;
                 }
             }
        }
    }
    
    for(int i = 0; i < tmpStr_vec.size(); i++){
        cout << "i=" << i << "\t" <<tmpStr_vec[i] << "\tnum=" << tmpInt_vec[i] <<endl;
        for(int j=0; j<tmpInt_vec[i]; j++){
           ret += tmpStr_vec[i];
        }
    }
    cout << ret <<endl;
    return ret;
}

int main()
{
    printf("a11b2bac3bad3abcd2\n");
    uncompress("a11b2bac3bad3abcd2");
    printf("****************************************\n");
    printf("abcdabcdbbbacbacbacbadbadbadaaaaaaaaaaa\n");
    return 0;
}
