#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
typedef long long len;
using namespace std;

int main()
{
    int N;
    while(cin >> N && N)
    {
        len squ=0;
        len area=0;
        len length[100010];
        stack<pair<len,int>> S;
        pair<len,int> a;
        int i;
        for(i=0;i<N;i++)
        {
            cin >> length[i];
        }
        length[i]=0;
        for(i=0;i<=N;i++)
        {
            a.first=length[i];
            a.second=i;
            if(S.empty())
               S.push(a);
            else if(S.top().first<a.first)
               S.push(a);
            else if(S.top().first>a.first)
            {
                int x=i;
                while(!S.empty()&&S.top().first>=a.first)
                {
                    pair<len,int> b=S.top();
                    S.pop();
                    area=b.first*(i-b.second);
                    squ=max(squ,area);
                    x=b.second;
                }
                a.second=x;
                S.push(a);
            }
        }
    cout << squ << endl;
    }
}