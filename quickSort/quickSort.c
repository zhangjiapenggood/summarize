#include<stdio.h>

// input 输入数据  len  输入数据的长度
void quickSort(int *input,int len)
{
    int tmp = 0;
    for(int i =0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(input[i] > input[j]){
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
    int a[] = {8,1,10,6,2,3,15};
    //因为在64位系统中int占4个字节，a总占用4*7=28个字节，由于int占用4个字节，因此数组的长度位28/4=7
    int len = sizeof(a)/sizeof(a[0]);
    //int len1 = sizeof(a)/sizeof(int);  //与上面的len相同
    quickSort(a,len);
    for(int i = 0; i< len;i++){
		printf("a[%d]=%d\n",i,a[i]);
    }
    return 0;
}
