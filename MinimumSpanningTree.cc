#include<iostream>
#include<algorithm>
using namespace std;

int P[101];

void init(int N)
{
	for (int i=0; i<N; ++i) 
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
	int n;
	cin >> n;
	init(n);
	int a[101][101];
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)
	       cin >> a[i][j];
	int M=0;
	int cost[10100],src[10100],dst[10100];
	for(int r=0;r<n;r++)
	   for(int c=r+1;c<n;c++)
	      if(a[r][c]>-1)
	      {
	      	cost[M]=a[r][c];
	      	src[M]=r;
	      	dst[M]=c;
	      	M++;
		  }
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
	cout << sum << endl;
}