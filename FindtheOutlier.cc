#include<iostream>
#include<cmath>

using namespace std;

int D;
double V[16];

double interpolate(int n, int E)
{
    double sum=0.0;
    for(int k=0; k<D+3; k++)
    {
        if(k==n || k==E)
          continue;
        double p=V[k];
        for(int i=0;i<D+3;i++)
           if(i!=k && i!=E && i!=n)
             p *=(double)(n-i)/(double)(k-i);
        sum +=p;
    }
    return sum;
}

bool outlier(int E)
{
    for(int i=0;i<D+3;i++)
    {
        if(i==E)
          continue;
        double p=interpolate(i, E);
        if(abs(p-V[i])>0.1)
          return false;
    }
    return true;
}

int main()
{
    while(cin >> D && D)
    {
        for(int i=0;i<D+3;i++)
           cin >> V[i];
        for(int i=0;i<D+3;i++)
           if(outlier(i))
           {
               cout << i << endl;
               break;
           }
    }
}