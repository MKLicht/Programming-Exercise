#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
    string cmd;
    int num;
    priority_queue<int> Q;
    while (cin >> cmd && cmd != "end")
    {
        if (cmd == "insert")
        {
            cin >> num;
            Q.push(num);
        }
        else if (cmd == "extract")
        {
            int n=Q.top();
            Q.pop();
            cout << n << endl;
        }
    }
}