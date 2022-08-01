#include<iostream>
using namespace std;

int main()
{
    int N,W;
    cin >> N >> W;
    int v[101],w[101];
    int V[101][10001];
    for(int i=1;i<=N;i++)
    {
        cin >> v[i] >> w[i];
    }
    int i,j;
    for(i=0;i<=N;i++)
       for(j=0;j<=W;j++)
          V[i][j]=0;
    for(i=1;i<=N;i++)
       for(j=1;j<=W;j++)
       {
           if(j-w[i]<0)
             V[i][j]=V[i-1][j];
           else
           {
              V[i][j]=max(v[i]+V[i][j-w[i]],V[i-1][j]);
           }
       }
    cout << V[N][W] << endl;
}