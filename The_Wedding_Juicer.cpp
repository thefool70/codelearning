#include <bits/stdc++.h>
using namespace std;
int juicer[301][301]={0};
int w;
int h;
int juice=0;
int temp_row[301];
int temp_col[301];
int temp_max[2];

void get_max(int x,int y)
{
  for(int i=0;i<w;i++)  temp_row[i]=juicer[x][i];
  for(int i=0;i<h;i++)  temp_col[i]=juicer[i][y];
  sort(temp_row,temp_row+w);
  sort(temp_col,temp_col+h);
  temp_max[0]=temp_row[w-1];
  temp_max[1]=temp_col[h-1];
}

void juice_cac()
{
  for(int i=1;i<h-1;i++)
  {
    for(int j=1;j<w-1;j++)
    {
    get_max(i,j);
    juice=min((temp_max[0]-juicer[i][j]),(temp_max[1]-juicer[i][j]))+juice;
  }
}
}

int main()
{
    cin>>w>>h;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w;j++)
         cin>>juicer[i][j];
    }
    juice_cac();
    cout<<juice;
    return 0;
}