#include<iostream>
#include<algorithm>
using namespace std;

int P[201];

void init(int N)
{
	for (int i=0; i<=N; ++i) 
	    P[i] = i;
} 

int root(int a)
{
	if(P[a]==a)   
	   return a;
	else  return(P[a]=root(P[a]));
}
 
bool is_same_set(int a,int b)
{
	return(root(a)==root(b));
}

void unite(int a,int b)
{
	P[root(a)]=root(b);
}

int kruskal(int src[101000],int dst[101000],int cost[101000],int n,int M)
{
    pair<int,int> edges[10100];
	for(int i=0;i<M;i++)
	{
		edges[i].first=cost[i];
		edges[i].second=i;
	}
	sort(edges,edges+M);
	int sum=0;
	for(int i=0;i<M;i++)
	{
		if(is_same_set(src[edges[i].second],dst[edges[i].second]))
		  continue;
		unite(src[edges[i].second],dst[edges[i].second]);
		sum+=edges[i].first;
	}
    int flag=1;
    for(int i=2;i<n;i++)
    {
        if(!is_same_set(1,i))
          flag=0;
    }
    if(!flag)
       sum=-1;
	return sum;
}

int main()
{
	int n,m;
	while(cin >> n >> m)
    {
        if(!n && !m)
          break;
        init(n);
        int h[201];
        for(int i=1;i<=n;i++)
           cin >> h[i];
	    int cost[101000],src[101000],dst[101000];
	    for(int i=0;i<m;i++)
	    {
            cin >> src[i] >> dst[i] >> cost[i];
		} 
        int sum=kruskal(src,dst,cost,n,m);
        int maxm=h[0];   
        for(int i=1;i<=n;i++)
        {
            maxm=max(maxm,h[i]);
        }     
        for(int i=1;i<=maxm;i++) 
        {
            for(int j=1;j<=n;j++)
               if(h[j]==i)
               {
                   int tmp;
                   
               }
            int add = kruskal(src,dst,cost,n,m);
            if(add==-1)
              break;
            sum+=add;
        } 
        cout << sum << endl;
     }
}