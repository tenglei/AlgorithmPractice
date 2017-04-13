#include <iostream>

using namespace std;
void insert_sort(int a[],int length){
    int i,j,tmp;
    if(length<0){
        cout<<"Array Index Error"<<endl;
        return ;
    }
    for(i=0;i<length;i++){
        for(j=i;j>0;j--){
            if(a[j]<a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
    for(i=0;i<length;i++){
        cout<<a[i]<<" ";
    }

}
int main()
{
    int a[10] = {2,3,4,21,54,0,3,2,43,9};
    insert_sort(a,10);
    return 0;
}
