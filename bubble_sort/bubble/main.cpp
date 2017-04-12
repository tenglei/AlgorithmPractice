#include <iostream>

using namespace std;
void bubble_sort(int a[],int length){
    int i,j,tmp;
    if(length<0){
        cout<<"Array index error"<<endl;
        return ;
    }
    try{
    for(i=length-1;i>=0;i--){
        for(j=0;j<i;j++){
            if(a[j]>a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    }
    catch(...){
        cout<<"Array index error"<<endl;
        return;
    }
}
int main()
{
    int a[10] = {3,5,3,2,7,9,334,2,7,0};
    bubble_sort(a,10);
    return 0;
}
