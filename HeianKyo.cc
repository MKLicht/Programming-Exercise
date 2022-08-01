#include<iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int k=0;k<N;k++)
    {
        int gx,gy,p;
        int x1[300],y1[300],x2[300],y2[300];
        cin >> gx >> gy;
        int vert[16][16],horiz[16][16];
        cin >> p;
        for(int i=0;i<=gx;i++)
           for(int j=0;j<=gy;j++)
           {
               vert[i][j]=1;
               horiz[i][j]=1;
           }
        for(int i=0;i<p;i++)
        {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
            if(x1[i]==x2[i])
              vert[x2[i]][max(y1[i],y2[i])]=0;
            else if(y1[i]==y2[i])
              horiz[max(x1[i],x2[i])][y2[i]]=0;
        }
        for(int i=0;i<=gx;i++)
            vert[i][0]=0;
        for(int j=0;j<=gy;j++)
            horiz[0][j]=0;
        int T[16][16];
        for(int i=0;i<=gx;i++)
           for(int j=0;j<=gy;j++)
              T[i][j]=0;
        for(int i=0;i<=gx;i++)
           for(int j=0;j<=gy;j++)
           {
               if(i==0&&j==0)
                 T[i][j]=1;
               else if(vert[i][j]==0&&horiz[i][j]==0)
                 T[i][j]=0;
               else if(vert[i][j]==0&&horiz[i][j])
                 T[i][j]=T[i-1][j];
               else if(horiz[i][j]==0&&vert[i][j])
                 T[i][j]=T[i][j-1];
               else if(vert[i][j]&&horiz[i][j])
                 T[i][j]=T[i-1][j]+T[i][j-1];
           }
        if(!T[gx][gy])
          cout << "Miserable Hokusai!" << endl;
        else
         cout << T[gx][gy] << endl;
    }
}