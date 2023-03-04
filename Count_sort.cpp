#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[20]={0};
int c[10];
int n;

int main()
{
  cin>>n;
 for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) b[a[i]]++;
  for(int cnt=0,last=0,now=0;now<20;now++) 
  {
    while(now<20&&b[now]==0) now++;
    if(cnt==0) {}
    else  b[now]=b[now]+b[last];
    last=now;
    cnt++;
  }
  for(int i=0;i<n;i++) 
  { 
    c[b[a[i]]-1]=a[i];
    b[a[i]]--;
  }

  for(int i=0;i<n;i++) printf("%d ",c[i]);

  return 0;
}
  
