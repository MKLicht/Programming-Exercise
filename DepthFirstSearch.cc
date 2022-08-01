#include<iostream>
#include<vector>
using namespace std;

int t=1;
int n;
int d[101],f[101];
int v[101];
vector<int> edges[101];

void dfs(int cur)
{
    if(d[cur]==-1)
    {
        d[cur]=t;
        v[cur]=1;
        t+=1;
    }
    int dst;
    for(dst=1;dst<=n;dst++)
    {
        int flag=0;
        for(int i=0;i<edges[cur].size();i++)
        {
            if(edges[cur][i]==dst)
				{
					flag=1;
					break;
				}
        }
        if(v[dst]==-1&&flag)
		  dfs(dst);
    }
    if(f[cur]==-1)
    {
        f[cur]=t;
        t+=1;
    }
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int u,k,y;
		cin >> u >> k;
		for(int j=0;j<k;j++)
        {
            cin >> y;
            edges[u].push_back(y);
        }
	}
	for(int i=1;i<=n;i++)
	{
        d[i]=-1;
        f[i]=-1;
        v[i]=-1;
    }
	for(int dst=1;dst<=n;dst++)
        dfs(dst);
	for(int i=1;i<=n;i++)
	   cout << i << ' ' << d[i] <<  ' ' <<  f[i] <<  endl;
}