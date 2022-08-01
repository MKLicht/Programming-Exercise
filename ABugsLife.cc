#include<iostream>
#include<vector> 
#include<queue>
using namespace std;

int color[1000010];
vector<int> edges[1000010];

int bfs(int src)
{
	queue<int> Q;
	Q.push(src);
    int dst;
	if(color[src]==0)
      color[src]=1;
	while(!Q.empty())
	{
		int cur=Q.front();
		Q.pop();
		for(int i=0;i<edges[cur].size();i++)
		{
			dst=edges[cur][i];
            if(color[dst])
			{
                if(color[dst]==color[cur])
                {
                    return 1;
                }
			}
            else
            {
                color[dst]=0-color[cur];
                Q.push(dst);
            }
        }
	}
    return 0;
}

int main()
{
    int N;
    int n,m;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&n,&m);
        for(int j=1;j<=n;j++)
           color[j]=0;
        for(int j=1;j<=n;j++)
              edges[j].clear();
        for(int j=0;j<m;j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int flag;
        for(int k=1;k<=n;k++)
        {
            flag=bfs(k);
            if(flag)
              break; 
        }
        printf("Scenario #%d:\n",i+1);
        if(flag)
          printf("Suspicious bugs found!\n");
        else
          printf("No suspicious bugs found!\n"); 
        printf("\n");
    }
}