#include<iostream>
#include<algorithm>
using namespace std;

int P[201];
int count[101000];

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
        count[i]--;
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
	    int cost[101000],src[101000],dst[101000];
        int judge[101000];
	    for(int i=0;i<m;i++)
            cin >> src[i] >> dst[i] >> cost[i]; 
        for(int i=0;i<m;i++)
        {
            count[i]=0;
            judge[i]=0;
            for(int j=0;j<m;j++)
               if(cost[i]==cost[j])
                 count[i]++;
        }
        int sum=kruskal(src,dst,cost,n,m);
        for(int i=0;i<m;i++)
        {
            if(count[i]==0)
              judge[i]=1;
        }
     }
}