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

/*void tree_sort(int*a,int n)
{
    if(2*n<=_size) tree_sort(a,2*n);
    if(2*n<=_size-1) tree_sort(a,2*n+1);
    if(2*n<=_size-1&&a[n]<a[2*n+1])  swap(a[2*n+1],a[n]);
    if(2*n<=_size&&a[n]<a[2*n]) swap(a[2*n],a[n]);
}*/

/*bool cmp(int a,int b)
{
    if (a>b) return true;
    else return false;
}*/

void tree_sort(int*a,int n)
{   if(n>_size/2) return;
    int l=2*n;
    int r=2*n+1;
    int largest=n;
    if(l<=_size&&a[n]<a[l])  largest=l;
    else largest=n;
    if(r<=_size&&a[l]<a[r]) largest=r;
    else largest=l;
    if(largest!=n)
    {
        swap(a[n],a[largest]);
        tree_sort(a,largest);
    }
}


int main()
{
  int*a=tree_make();
  tree_print(a);
  cout<<endl;
  for(int i=_size/2;i>1;i--) tree_sort(a,i);
  tree_print(a);
}