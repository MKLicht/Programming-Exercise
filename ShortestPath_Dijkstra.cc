#include<iostream>
#include <cstdio>
#include<queue>
using namespace std;

int V, E, R, S[500010], T[500010],D[500010];
int C[100010];
const int Inf = 10000*100000+100;
vector< pair<int,int> >G[500010];

int main()
{
    scanf("%d %d %d",&V, &E, &R);
    for(int i=0;i<E;i++)
    {
        scanf("%d %d %d",&S[i], &T[i], &D[i]);
        G[S[i]].push_back(make_pair(T[i],D[i]));
    }
    for(int i=0;i<V;i++)
    {
        if(i==R)
          C[R]=0;
        else
          C[i]=Inf;
    }
    priority_queue< pair<int,int> > Q;
    pair<int,int> a;
    a.first=0;
    a.second=R;
    Q.push(a);
    int s,t,d;
    while(!Q.empty())
    {
        a=Q.top();
        Q.pop();
        s=a.second;
        if(C[s]< 0-a.first)
           continue;
        C[s]=0-a.first;
        int l=G[s].size();
        for(int i=0;i<l;i++)
        {
            t=G[s][i].first;
            d=G[s][i].second;
            if(C[t]>0-(C[s]+d))
              Q.push(make_pair(0-(C[s]+d),t));
        }
    }
    for(int i=0;i<V;i++)
    {
        if(C[i]==Inf)
          printf("INF\n");
        else
          printf("%d\n",C[i]);
    }
}