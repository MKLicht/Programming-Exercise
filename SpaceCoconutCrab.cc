#include<iostream>
using namespace std;

int solve(int E)
{
    int ans=E;
    int x;
    for(int z=0;z*z*z<=E;z++)
       for(int y=0;y*y<=E-z*z*z;y++)　　
       {
           x=E-y*y-z*z*z;
           ans=min(ans,x+y+z);
       }
    return ans;
}

int main()
{
    int E;
    while(cin >> E && E>0)
         cout << solve(E) << endl;
}