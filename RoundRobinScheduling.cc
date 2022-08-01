#include<iostream>
#include<cstdlib>
#include<queue>
#include<string>
using namespace std;

struct Process
{
    string name;
    int time;
    int left;
}pro[100000];

int main()
{
    int t=0;
    int n,q;
    cin >> n >> q;
    queue<Process> Q;
    for(int i=0;i<n;i++)
    {
        cin >> pro[i].name >>pro[i].time;
        pro[i].left=pro[i].time;
        Q.push(pro[i]);
    }
    while(!Q.empty())
    {
        Process job=Q.front();
        Q.pop();
        if(job.left>q)
        {
            t+=q;
            job.left-=q;
            Q.push(job);
        }
        else
        {
            t+=job.left;
            cout << job.name << ' ' << t << endl;
        }
    }
}