#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>

#define INF 1000000
using namespace std;

int M,N;
int X1[210], Y[210], X2[210], Z[210];

double width(int p[210], int q[210], int n, double x)
{
    double a=INF,b=-INF;
    for(int i=0;i<n;i++)
	{
        double x1=p[i], x2=p[(i+1)%n];
        double y1=q[i], y2=q[(i+1)%n];
        if((x1-x)*(x2-x)<=0 && x1!=x2)
		{
            double y=y1+(y2-y1)*(x-x1)/(x2-x1);
            a=min(a,y);
            b=max(b,y);
        }
    }
    if(b-a>0)
      return b-a;
    else
      return 0.0;
}

double volume()
{
	int x1min, x2min, x1max, x2max;
	x1min=*min_element(X1, X1+M);
	x1max=*max_element(X1, X1+M);
	x2min=*min_element(X2, X2+M);
	x2max=*max_element(X2, X2+M);
	int A[420];
	for(int i=0;i<M;i++)
	{
		A[i]=X1[i];
	}
	for(int i=M;i<M+N;i++)
	{
	   A[i]=X2[i-M];	
	}
	sort(A,A+M+N);
	double total=0.0;
	for(int i=0;i+1<M+N;i++)
	{
		double a=A[i], b=A[i+1];
		double c=(a+b)/2.0;
		if(c>=x1min&&c<=x1max&&c>=x2min&&c<=x2max)
		{
			double fa, fb, fc;
			fa=width(X1,Y,M,a)*width(X2,Z,N,a);
			fb=width(X1,Y,M,b)*width(X2,Z,N,b);
			fc=width(X1,Y,M,c)*width(X2,Z,N,c);
			total+=(b-a)/6*(fa+4*fc+fb);
		}
	}
	return total;
}

int main()
{
    while(cin >> M >> N)
	{
		for(int i=0;i<210;i++)
		{
			X1[i]=0;
			Y[i]=0;
			X2[i]=0;
			Z[i]=0;
		}
		if(!M&&!N)
		  break;
		for(int i=0;i<M;i++)
		   cin >> X1[i] >> Y[i];
		for(int i=0;i<N;i++)
		   cin >> X2[i] >> Z[i];   
		double sum=volume();
		printf("%.10f\n",sum);
	}	
} 