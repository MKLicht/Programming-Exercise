#include<iostream>
#include <cstdio>
using namespace std;

int N,M,A,B,C,D,s,g,V,P;
int cost[32][32];
int length[32][32];
const int Inf = 10000*100000+100;

int main()
{
    scanf("%d%d", &N, &M); 
    for(int i=1;i<=N;i++)
       for(int j=1;j<=N;j++)
       {
           if(i==j)
             cost[i][j]=0;
           else
             cost[i][j]=Inf;
       }
    for (int i=0; i<M; ++i) 
    {
        scanf("%d,%d,%d,%d", &A, &B, &C, &D);
        cost[A][B]=C;
        cost[B][A]=D;
    }
    for(int i=1;i<=N;i++)
       for(int j=1;j<=N;j++)
       {
           length[i][j]=cost[i][j];
       }
    for(int k=1;k<=N;k++)
       for(int i=1;i<=N;i++)
          for(int j=1;j<=N;j++)
             if(length[i][k]+length[k][j]<length[i][j])
               length[i][j]=length[i][k]+length[k][j];
    scanf("%d,%d,%d,%d", &s, &g, &V, &P);
    int reward=V-P-length[s][g]-length[g][s];
    printf("%d\n",reward);
}