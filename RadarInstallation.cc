#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

pair<double,double> ISL[10000];

bool cmp(pair<double,double> a,pair<double,double> b)
{
    if(a.first==b.first)
      return a.second>b.second;
    return a.first<b.first;
}

int main()
{
    int n,d;
    int k=0;
    while(cin >> n >> d && n)
    {
        k++;
        double x,y;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin >> x >> y;
            if(y>d||d<0)
            {
                flag=1;
            }
            ISL[i]=make_pair(x+sqrt(double(d*d)-y*y),x-sqrt(double(d*d)-y*y));
        }
        if(flag)
        {
            int a=-1;
            cout << "Case " << k << ": " << a << endl;
        }
        else
        {
            sort(ISL,ISL+n,cmp);
            int count=1;
            double s=ISL[0].first;
            for(int i=0;i<n;i++)
            {
                if(ISL[i].second>s)
                {
                    s=ISL[i].first;
                    count++;
                }
            }
            cout << "Case " << k << ": " << count << endl;
        }
    }
}