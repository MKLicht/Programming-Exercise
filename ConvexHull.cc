#include<iostream>
#include<cstdio>
#include<complex>
#include<cmath>
#include<algorithm>
using namespace std;
typedef complex<double> xy_t;

xy_t P[110];
int judge[110];

bool cmp(xy_t a, xy_t b)
{
    if(a.real()==b.real())
      return a.imag()<b.imag();
    return a.real()<b.real();
}

double cross_product(xy_t a, xy_t b)
{
    return (conj(a)*b).imag();
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n==0)
          break;
        double x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%lf,%lf", &x, &y);
            P[i]=xy_t(x,y);
        }
        sort(P,P+n,cmp);
        for(int i=0;i<n;i++)
           judge[i]=0;
        int sum=0;
        xy_t a=P[0], b=P[1], c=P[2];
        int i=0, j=1, k=2;
        while(k<=n-1)
        {
            while(cross_product(b-a,c-a)<=0)
            {
                while(b.real()==c.real())
                {
                    c=P[k+1];
                    k++;
                }
                b=c;
                j=k;
                c=P[k+1];
                k++;
            }
            a=b;
            judge[i]=1;
            i=j;
            b=c;
            judge[j]=1;
            j=k;
            c=P[k+1];
            judge[k]=1;
            k++;
        }
        a=P[n-1], b=P[n-2], c=P[n-3];
        i=n-1, j=n-2, k=n-3;
        while(k>=0)
        {
            while(cross_product(b-a,c-a)<=0 || (judge[j]==1 && j!=0) || (judge[k]==1 && k!=0))
            {
                b=c;
                j=k;
                c=P[k-1];
                k--;
            }
            a=b;
            judge[i]=1;
            i=j;
            b=c;
            judge[j]=1;
            j=k;
            c=P[k-1];
            judge[k]=1;
            k--;
        } 
        for(int i=0;i<n;i++)
        {
            if(judge[i]==0)
            {
                sum++;
                cout << P[i].real() << P[i].imag() << endl;
            }
        }
        cout << sum << endl;
    }
}