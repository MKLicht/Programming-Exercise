#include<iostream>
using namespace std;

int P[100100],v[100100];

void init(int N)
{
	for(int i=0; i<=N; ++i) 
	    P[i] = i;
} 

int root(int a)
{
    if(P[a]==a)   
	   return a;
    int x=P[a];
    P[a]=root(P[a]);
    v[a]+=v[x];
    return P[a];    
}
 
bool is_same_set(int a,int b)
{
	return(root(a)==root(b));
}

void unite(int a,int b,int w)
{
	int u=root(a);
	int m=root(b);
	P[m]=u;
	v[m]=v[a]-v[b]+w;
}

int main()
{
    int M,N;
    while(cin >> N >> M)
    {
        if(!N && !M)
          break;
        init(N);
        for(int i=1;i<=N;i++)
           v[i]=0;
        for(int i=0;i<M;i++)
        {
            char c;
            int a,b,w;
            cin >> c;
            if(c=='?')
            {
                cin >> a >> b;
                if(!is_same_set(a,b))
                   cout << "UNKNOWN" << endl;
                else
                   cout << v[b]-v[a] << endl;
            }
            else if(c=='!')
            {
                cin >> a >> b >> w;
                unite(a,b,w);
            }
        }
     }
}