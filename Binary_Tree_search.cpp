#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
 Node* parent=NULL;
 Node* left=NULL;
 Node* right=NULL;
 int key;
} node;
node* head = NULL;

void insert(int data){
node*p=head;
node*p0;
node*pNext=(node*)malloc(sizeof(node));
pNext->key=data;
pNext->left=NULL;
pNext->right=NULL;
if(p==NULL)  head =pNext;
else {while(p!=NULL)
{  p0=p;
   if(data>p->key) p=p->left;
   else p=p->right;
} if(data<p0->key) p0->right=pNext;
    else           p0->left=pNext;
    pNext->parent=p0;
 }
}

void print(node*p)
{ if(p==NULL) return;
  //  cout<<p->key; //前序遍历
  print(p->left);
  cout<<" "<<p->key; //中值遍历 按从大到小顺序遍历
  print(p->right);
  // cout<<p->key; //后序遍历
}

void find(node*p,int x)
{
   if(p->key == x) {cout<<"yes"<<endl; return ;}
   else if(p->left!=NULL&&p->key < x) find(p->left,x);
   else if(p->right!=NULL&&p->key>x) find(p->right,x);
   else {cout<<"no"<<endl; return ;}
}

int main()
{ 
    int n;
    string com;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>com;
        if(com=="ins")
        {
            int data;
            cin>>data;
            insert(data);
        }
        else if(com=="pri")
        {  print(head);
            cout<<endl;
        }
        else
        {
            int data;
            cin>>data;
            find(head,data);
        }
    }  
    return 0;
}