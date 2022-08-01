#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    typedef set<string> set_t;
    set_t A;
    string cmd;
    string word;
    int n; 
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> cmd;
        if(cmd == "insert")
        {
            cin >> word;
            A.insert(word);
        }
        else if(cmd=="find")
        {
            cin >> word;
            if(A.count(word)==0)
              cout << "no" << endl;
            else 
              cout << "yes" << endl;
        }
    }
}