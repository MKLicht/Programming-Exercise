#include<iostream>
#include <cstdio>
using namespace std;

int n,m,c,s,g;
int x[10010],y[10010],d[10010],c[10010];
int p[30],q[10010][30],r[10010][30];
int main()
{
    scanf("%d %d %d %d %d",&n,&m,&c,&s,&g);
    for(int i=0;i<m;i++)
       scanf("%d %d %d %d", &x[i],&y[i],&d[i],&c[i]);
    for(int i=1;i<=c;i++)
       scanf("%d",&p[i]);
    for(int i=1;i<=c;i++)
       for(int j=1;j<=p[i];j++)
          scanf("%d",&q[i][j]);
       for(int j=1;j<=p[i];j++)
          scanf("%d",&r[i][j]);
    
}