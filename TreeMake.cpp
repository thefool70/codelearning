#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int parent=-1;
    int left=-1;
    int right=-1;
}node ;
node nodes[100];
int temp[100]={0};

int get_depth(int n)
{int depth=0;
  while(nodes[n].parent!=-1)
  {
    n=nodes[n].parent;
    depth++;
  }
return depth;
}

void print_node(int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<"node "<<i<<" "<<nodes[i].parent<<" ";
    cout<<"depth "<<get_depth(i)<<" ";
    if(nodes[i].left==-1) cout<<"exNode ";
    else {cout<<"inNode "<<"["<<nodes[i].left;
    int j=nodes[i].left;
    while(nodes[j].right!=-1&&cout<<",")
    {
        cout<<nodes[j].right;
        j=nodes[j].right;
    }
    cout<<"]";}
    cout<<endl;
  }
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m,degree;
        cin>>m;//父节点
        cin>>degree;//子节点个数
        if(degree==0) {}
        else{
        for(int j=0;j<degree;j++)
        {cin>>temp[j];
        if(j==0) nodes[m].left=temp[j];//左子
        else if(j==degree-1){
        nodes[j].right=-1;
        nodes[temp[j-1]].right=temp[j];}
        else {
            nodes[temp[j-1]].right=temp[j];//右兄
        }
        nodes[temp[j]].parent=m;
        }}
    }
    print_node(n);
    return 0;
}
