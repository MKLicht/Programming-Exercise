#include<iostream>
#include<vector> 
#include<queue>
using namespace std;

int x,y;
int ti[51][51];
const int dx[]={1,0,-1,0,-1,1,-1,1}, dy[]={0,-1,0,1,-1,1,1,-1};

bool valid(int i,int j)
{
	return(i>=0&&i<y&&j>=0&&j<x);
}

int bfs(int m,int n)
{
	if(ti[m][n]==0)
      return 0;
    queue< pair<int,int> > Q;
	pair<int,int> a,b;
	a.first=m;
	a.second=n;
	Q.push(a);
	while(!Q.empty())
	{
		a=Q.front();
		Q.pop();
		for(int i=0;i<8;i++)
		{
			b.first=a.first+dx[i];
			b.second=a.second+dy[i];
			if(valid(b.first, b.second) && ti[b.first][b.second])
			{
				ti[b.first][b.second]=0;
				Q.push(b);
			}
		}
	}
	return 1;
}

int main()
{
	while(cin >> x >> y)
	{
		if(!x&&!y)
		  break;
		for(int i=0;i<y;i++)
		   for(int j=0;j<x;j++)
		   {
		   	    cin >> ti[i][j];
		   }
        int sum=0;
        for(int i=0;i<y;i++)
		   for(int j=0;j<x;j++)
              if(bfs(i,j))
              {
                  sum++;
              }
        cout << sum << endl;
	}
}