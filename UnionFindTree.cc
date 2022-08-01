#include<iostream>
using namespace std;

int P[10010];

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
	int n,q;
	cin >> n >> q;
	init(n);
	for(int i=0;i<q;i++)
	{
		int com,m,n;
		cin >> com >> m >> n;
		if(!com)
		   unite(m,n);
		else
			cout << is_same_set(m,n) << endl;	
	}
}