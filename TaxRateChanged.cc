#include<iostream>
using namespace std;

int tax(int,int);

int main()
{
    int X,Y,S;
    int maximum;
    while(cin >> X >> Y >> S && X>0 && Y>0 && S>0)
    {
        maximum=0;
        for(int i=1;i<S;i++)
           for(int j=i;j<S;j++)
              if(tax(X,i)+tax(X,j)==S)
                maximum=max(maximum,tax(Y,i)+tax(Y,j));
        cout << maximum << endl;
    }
}

int tax(int x,int price)
{
    return(price*(100+x)/100);
}