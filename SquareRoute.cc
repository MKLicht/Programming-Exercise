#include<iostream>
using namespace std;

typedef struct 
{
    int x;
    int y;
}Point;

int Count_Square(int N,int M)
{
    int h[1500],w[1500];
    int count=0;
    int i,j,k,l;
    Point S[1500][1500]; 
    for(i=0;i<N;i++)
       cin >> h[i];
    for(i=0;i<M;i++)
       cin >> w[i];
    for(i=0;i<N;i++)
       for(j=0;j<M;j++)
       {
           S[i][j].x=S[i][j].y=0;
           for(k=0;k<i+1;k++)
              S[i][j].x+=w[k];
           for(k=0;k<j+1;k++)
              S[i][j].y+=h[k];
       }
    for(i=0;i<N;i++)
       for(j=0;j<M;j++)
           for(k=i+1;k<N;k++)
              for(l=j+1;l<M;l++)
                 if(S[i][j].x-S[k][l].x==S[i][j].y-S[k][l].y)
                   count++;
    return count;
}


int main()
{
    int N,M;
    while(cin >> N >> M && N>0 && M>0)
          cout << Count_Square(N,M) << endl;
}