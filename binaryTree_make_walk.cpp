#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int parent=-1,left=-1,right=-1;
} node;
node nodes[10001];
int n;

void treeMake()
{
   for(int i=0;i<n;i++)
   {
    int l,r,b;
    scanf("%d",&b);
    cin>>l>>r;
    getchar();
    nodes[b].left = l;
    nodes[b].right = r;
    nodes[l].parent = b;
    nodes[r].parent = b;
   }
}

void treeDisplay1(int b)
{
  if(nodes[b].left!=-1) treeDisplay1(nodes[b].left);
  if(nodes[b].right!=-1) treeDisplay1(nodes[b].right);
   cout<<b<<" ";//特别注意:运用if时一定要搞清楚是异或关系还是平行关系!!
}

void treeDisplay2(int b)
{ cout<<b<<" ";
  if(nodes[b].left!=-1) treeDisplay2(nodes[b].left);
  if(nodes[b].right!=-1) treeDisplay2(nodes[b].right);
}

void treeDisplay3(int b)
{ 
  if(nodes[b].left!=-1) treeDisplay3(nodes[b].left);
  cout<<b<<" ";
  if(nodes[b].right!=-1) treeDisplay3(nodes[b].right);
}

int main()
{   cin >> n;
    treeMake(); 
    treeDisplay1(0); cout<<endl;
    treeDisplay2(0); cout<<endl;
    treeDisplay3(0); cout<<endl;
    return 0;
}