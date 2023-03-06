#include <bits/stdc++.h>
using namespace std;
int _size;
int p[100]={0};

void tree_make()
{
  cin>>_size;
  for(int i=1;i<=_size;i++) cin>>p[i];
}

void tree_print(int *a)
{
for(int i=1;i<=_size;i++)
{
    cout<<"Node"<<i<<":"<<a[i]<<" ";
    if(i/2!=0) cout<<"parent:"<<a[i/2];
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
    if(r<=_size&&a[largest]<a[r]) largest=r;
    if(largest!=n)
    {
        swap(a[n],a[largest]);
        tree_sort(a,largest);
    }
}


void insert(int x)
{
   _size++;
   p[_size]=x;
   for(int i=_size/2;i>=1;i--) tree_sort(p,i);
}

void dele(int*a)
{ 
  cout<<a[1]<<endl;
  a[1]=a[_size+1];
  _size--;
  for(int i=_size/2;i>=1;i--) tree_sort(p,i);
}

int main()
{
  tree_make();
  for(int i=_size/2;i>=1;i--) tree_sort(p,i);
  tree_print(p); cout<<endl;
  dele(p);
 // tree_print(p); cout<<endl;
 // insert(100);
  tree_print(p);
}