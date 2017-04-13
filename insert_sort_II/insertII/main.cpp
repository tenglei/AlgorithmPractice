#include <iostream>

using namespace std;
int binary_search_index(int a[],int f,int b,int t){
   int mid;
   while(f<b){
    mid = (f+b)/2;
    if(a[mid]>t){
        b = mid-1;
    }
    else if(a[mid]<t){
        f = mid +1;
    }
    else{
        return mid;
    }
   }
   return f;
}
void insert_sortII(int a[],int length){
    int i,j,index,tmp;
    for(i=1;i<length;i++){
        if(a[i]<a[i-1]){
            index = binary_search_index(a,0,i-1,a[i]);
            tmp=a[i];
            for(j=i;j>=index;j--){
                a[j] = a[j-1];
            }
            a[index] = tmp;
        }
    }
    for(i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[10] = {6,5,4,3,2,66,7,8,9,1};
    insert_sortII(a,10);
    return 0;
}
