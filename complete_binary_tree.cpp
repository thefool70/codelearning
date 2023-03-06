#include <bits/stdc++.h>
using namespace std;
int _size;

int* tree_make()
{
  cin>>_size;
  int*p=(int*)(malloc(sizeof(int)*(_size)+1));
  for(int i=1;i<=_size;i++) cin>>p[i];
  return p;
}

void tree_print(int *a)
{
for(int i=1;i<=_size;i++)
{
    cout<<"Node"<<i<<":"<<a[i]<<" ";
    if(i/2!=0) cout<<"parent:"<<i/2;
    if(2*i<=_size) cout<<"left:"<<a[2*i];
    if(2*i<=_size-1)  cout<<"right:"<<a[2*i+1];
    cout<<endl;
}
}

int main()
{
  int*a=tree_make();
  tree_print(a);
}