#include <iostream>
#include<limits.h>
using namespace std;
void select(int a[],int length){
    int i,j,k,Max,tmp;
    for(i=length-1;i>=0;i--){
        Max=INT_MIN;
        for(j=0;j<=i;j++){
            if(a[j]>=Max){
                Max = a[j];
                k = j;
            }
        }
        tmp=a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
    for(i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[10] = {4,65,43,2,4,6,7,9,4,1};
    select(a,10);
    return 0;
}
