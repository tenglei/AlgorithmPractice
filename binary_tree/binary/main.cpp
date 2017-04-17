#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
typedef struct node {
int data;
struct node *left;
struct node *right;
};
node *btree(int n,struct node *&root){
    if(root==NULL){
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = n;
        return root;
    }
    if(n<root->data){
       // cout<<root->data<<" "<<n<<endl;
        btree(n,root->left);
    }
    else if(n>root->data){
       // cout<<root->data<<" "<<n<<endl;
        btree(n,root->right);
    }
    return root;
}
void ptree(int n,struct node *root){
    if(root==NULL){
        cout<<n;
        return;
    }
    if(n<root->data){
        cout<<root->data<<",";
        ptree(n,root->left);
    }
    else if(n>root->data){
        cout<<root->data<<",";
        ptree(n,root->right);
    }else{
        cout<<n;
        return;
    }
}
int main(){
   string in;
   int n;
   cin>>in;
   vector<int> numGroup;
   vector<char> ntmp;
   int k,l;
     int i=0;
     i++;
     while(in[i]!=']'){
        vector<char> tmp;
        while(in[i]!=','){
            tmp.push_back(in[i]);
            i++;
            if(in[i]==']'){
                break;
            }
        }
        int p,t=0;
        p=0;
        while(tmp.size()!=0){
            t+=(tmp.back()-48)*pow(10,p);
            tmp.pop_back();
            p++;
        }
        numGroup.push_back(t);
        if(in[i]==']'){
            break;
        }
        i++;
     }
     i+=2;
     for(;i<in.length();i++){
        ntmp.push_back(in[i]);
     }
     k=0;
     l=0;
     while(ntmp.size()!=0){
        k+=(ntmp.back()-48)*pow(10,l);
        ntmp.pop_back();
        l++;
     }
     node *root = new node;
     root->data = numGroup[0];
     root->left = NULL;
     root->right = NULL;
     for(int i=1;i<numGroup.size();i++){
       btree(numGroup[i],root);
     }
    cout<<'[';
    ptree(k,root);
	cout<<']';





}
