#include<iostream>
#include<string>
#include<cassert>
#include<cctype>
using namespace std;

string s;
int cur=0;

char readchar()
{
    assert(cur<s.size());
    char ret=s[cur];
    cur+=1;
    return ret;
}

char peek()
{
    assert(cur<s.size());
    return s[cur];
}

int digit()
{
    assert(isdigit(peek()));
    int n = readchar() - '0';
    return n;
}

int number()
{
    int n=digit();
    while (cur < s.size() && isdigit(peek()))
       n=n*10+digit();
    return n;
}

int expression();

int factor()
{
    if(peek()!='(')  
      return number();
    cur+=1;
    int n=expression();
    assert(peek()==')');
    cur+=1;
    return n;
}

int term()
{
    int a=factor();
    while((cur<s.size()) && (peek()=='*'||peek()=='/'))
    {
        char op=readchar();
        int b=factor();
        if(op =='*')  a *=b;
        else a /=b;
    }
    return a;
}

int expression()
{
    int a=term();
    while(cur<s.size()&&(peek()=='+'||peek()=='-'))
    {
        char op=readchar();
        int b=term();
        if(op=='+')  a +=b;
        else  a -=b;
    }
    return a;
}

int parse()
{
    return expression();
}

int main()
{
    int n,a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        cur=0;
        a=parse();
        cout << a << endl;
    }
}