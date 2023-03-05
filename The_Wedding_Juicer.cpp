#include <bits/stdc++.h>
using namespace std;
int juicer[301][301]={0};
int w;
int h;
int juice=0;

int Min(int x,int y,int m,int n)
{
return  min(min(x,y),min(m,n));
}

void juice_cac()
{
  for(int i=1;i<w+1;i++)
  {
    for(int j=1;j<h+1;j++)
    {
      int low=Min(juicer[i][j-1],juicer[i][j+1]
      ,juicer[i-1][j],juicer[i+1][j]);
      if(low<=juicer[i][j]) {}
      else juice=juice+low-juicer[i][j];
  }
}
}

int main()
{
    cin>>w>>h;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w;j++)
         cin>>juicer[i+1][j+1];
    }
    juice_cac();
    cout<<juice;
    return 0;
}