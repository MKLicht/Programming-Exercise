#include<string>
#include<cstring>
#include<stack>
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    string word;
    stack<int> S;
    int num;
    int count=-1;
    while(cin >> word)
    {
        count++;
        if(word=="+")
        {
            int a=S.top(); S.pop();
            int b=S.top(); S.pop();
            num=a+b;
            S.push(num);
        }
        else if(word=="-")
        {
            int a=S.top(); S.pop();
            int b=S.top(); S.pop();
            num=b-a;
            S.push(num);
        }
        else if(word=="*")
        {
            int a=S.top(); S.pop();
            int b=S.top(); S.pop();
            num=a*b;
            S.push(num);
        }
        else
        {
            num=atoi(word.c_str());
            S.push(num);
        }
     }
    int n=S.top();
    cout <<n<< endl;
}