#include<iostream>
#include<algorithm>
using namespace std;

int P[101];

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

int main()
{
	int n,m;
	while(cin >> n >> m)
    {
        if(!n && !m)
          break;
        init(n);
	    int cost[101000],src[101000],dst[101000];
	    for(int i=0;i<m;i++)
	    {
            cin >> src[i] >> dst[i] >> cost[i];
		}
	    pair<int,int> edges[101000];
	    for(int i=0;i<m;i++)
	    {
		    edges[i].first=cost[i];
		    edges[i].second=i;
	    }
	    sort(edges,edges+m);
        int flag=100000;
	    for(int i=0;i<m;i++)
	    {
            int count=0;
            init(n);
            for(int j=i;j<m;j++)
            {
                if(is_same_set(src[edges[j].second],dst[edges[j].second]))
		          continue;
		        unite(src[edges[j].second],dst[edges[j].second]);
                count++;
                if(count==n-1)
                {
                   flag=min(edges[j].first-edges[i].first,flag);
                   break;
                }   
            }
	    }
        if(flag==100000)
          flag=-1;
	    cout << flag << endl;
    }
}