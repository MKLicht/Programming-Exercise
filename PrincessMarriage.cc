#include<algorithm>
#include<iostream>
using namespace std;

int N,M;
pair<int,int> PD[10010];

int main()
{
    while(cin >> N >> M && N)
    {
        int d,p;
        for(int i=0;i<N;i++)
        {
            cin >> d >>p;
            PD[i]=make_pair(p,d);
        }
        sort(PD,PD+N);
        int S=0;
        for(int i=0;i<N;i++)
           S+=PD[i].first*PD[i].second;
        for(int i=N-1;i>=0;i--)
        {
            if(M<=0)   break;
            int guard=min(M,PD[i].second);
            S-=PD[i].first*guard;
            M-=guard;
        }
        cout << S <<endl;
    }
}