#include<iostream>
#include<vector> 
using namespace std;

int x,y;
char ti[30][30];
const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
int sum=0;

bool valid(int i,int j)
{
	return(i>=0&&i<y&&j>=0&&j<x);
}

void dfs(int m,int n)
{
	sum++;
	ti[m][n]='#';
	for(int i=0;i<4;i++)
	{
		int x,y;
		x=m+dx[i];
		y=n+dy[i];
		if(valid(x,y) && ti[x][y]=='.')
		  dfs(x,y);
	}
}

int main()
{
	int m,n;
	while(cin >> x >> y)
	{
		sum=0;
		if(!x&&!y)
		  break;
		for(int i=0;i<y;i++)
		   for(int j=0;j<x;j++)
		   {
		   	    cin >> ti[i][j];
		   	    if(ti[i][j]=='@')
		   	    {
		   	    	m=i;
		   	    	n=j;
				}
		   }
		dfs(m,n);
	    cout << sum << endl;
	}
}