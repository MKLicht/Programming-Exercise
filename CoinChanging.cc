#include<iostream>
using namespace std;
#define INIFY 5000000

int main()
{
    int n,m;
    cin >> n >> m;
    int coin[21];
    int count[21][50001];
    for(int i=1;i<=m;i++)
    {
        cin >> coin[i];
    }
    int i,j;
    for(i=0;i<=m;i++)
       count[i][0]=0;
     for(j=1;j<=n;j++)
         count[0][j]=INIFY;
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
       {
           if(j-coin[i]<0)
             count[i][j]=count[i-1][j];
           else
             count[i][j]=min(1+count[i][j-coin[i]],count[i-1][j]);
       }
    cout << count[m][n] << endl;
    }