#include<algorithm>
#include<iostream>
using namespace std;

int T,N,K,X[100000+10],A[100000+10];

int main()
{
    cin >> T;
    for(int t=0;t<T;t++)
    {
        cin >> N >> K;
        for(int i=0;i<N;i++)
           cin >> X[i];
        for(int i=0;i<N-1;i++)
           A[i]=X[i+1]-X[i];
        sort(A,A+N-1);
        int sum=0;
        for(int i=0;i<N-1-(K-1);i++)
            sum+=A[i];
        cout << sum << endl; 
    }
}