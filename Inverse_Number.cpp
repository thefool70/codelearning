#include <bits/stdc++.h>
using namespace std;
int a[10];
int le[5];
int ri[5];
int cnt=0;
#define maxN 999999;

int get(int l,int r)
{
  int m=(l+r)/2;
  int n1=m-l;
  int n2=r-m;
  for(int i=0;i<n1;i++) le[i]=a[l+i];
  le[n1]=maxN;
  for(int i=0;i<n2;i++) ri[i]=a[m+i];
  ri[n2]=maxN;
  int j=0,k=0;
  for(int i=l;i<r;i++)
  {
    if(le[j]<ri[k])
    {
      a[i]=le[j];
      j++;
    }
    else {
      a[i]=ri[k];
      cnt=cnt+n1-j;
      k++;
    }
  }
return 0;
}

int getNum(int left, int right)
{  if (left +1 >= right) return 0;
   int middle =(left+right)/2;
   getNum(left,middle);
   getNum(middle,right);
   get(left,right);
   return 0;
}

int main()
{   int n;
    cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  getNum(0,n);
  cout<<cnt;
}