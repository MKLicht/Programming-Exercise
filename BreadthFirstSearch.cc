#include<iostream>
#include<vector> 
#include<queue>
using namespace std;

int D[101]; 
int edges[101][101];

void bfs(int src,int n)
{
	queue<int> Q;
	Q.push(src);
	D[src]=0;
	while(!Q.empty())
	{
		int cur=Q.front();
		Q.pop();
		for(int dst=1;dst<=n;dst++)
		{
			int flag=0;
			for(int i=0;i<n;i++)
			{
				if(edges[cur][i]==dst)
				{
					flag=1;
					break;
				}
			}
			if(D[dst]==-1&&flag)
			{
				D[dst]=D[cur]+1;
				Q.push(dst);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int u,k;
		cin >> u >> k;
		for(int j=0;j<k;j++)
		   cin >> edges[u][j];
	}
	for(int i=1;i<=n;i++)
	   D[i]=-1;
	bfs(1,n);
	for(int i=1;i<=n;i++)
	   cout << i << ' ' << D[i] << endl;
}