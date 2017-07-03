#include <iostream>
#include "time.h"
#include "vector"
#include "stdlib.h"
using namespace std;
int random(int a,int b){
    int c;
    c = (rand()%(b-a+1))+a;
    return c;
}
vector<int> initData(int a,int b,int length){
    vector<int> test;
    int tmp;
    for(int i=0;i<length;i++){
        tmp = random(0,50);
        test.push_back(tmp);
        cout<<tmp<<" ";
    }
    cout<<endl;
    return test;
}
void quickSort(vector<int> &s,int i,int j){
    int head,tail,l,r;
    head = i;
    tail = j;
    if(i<j){
        int tmp;
        l = s[head];
        r = s[tail];
        tmp = l;
        while(head<tail){
            while(head<tail&&l<s[tail]){
                tail--;
            }
            if(head<tail){
                s[head++] = s[tail];
            }
            while(head<tail&&l>s[head]){
                head++;
            }
            if(head<tail){
                s[tail--] = s[head];
            }
        }
        cout<<"head:"<<head<<endl;
        s[head] = tmp;
        if(head!=0){
            quickSort(s,i,head-1);
        }
        if(head!=s.size()-1){
            quickSort(s,head+1,j);
        }
    }

}
int main()
{
    int tmp;
    vector<int> test;
    test = initData(0,50,20);
    srand((unsigned)time(0));
    quickSort(test,0,test.size()-1);
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<" ";
    }
    return 0;
}
