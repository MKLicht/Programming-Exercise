#include<iostream>
using namespace std;

int F[100];
int main()
{
    int N;
    cin >> N;
    F[0]=1;
    F[1]=1;
    for(int i=2;i<=N;i++)
       F[i]=F[i-2]+F[i-1];
    cout << F[N] << endl;
}