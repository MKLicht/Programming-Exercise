#include<iostream>
#include<string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int k=0;k<N;k++)
    {
        string word1,word2;
        cin >> word1;
        cin >> word2;
        int L[2000][2000];
        for(int i=0;i<word1.size();i++)
           for(int j=0;j<word2.size();j++)
           {
               if(i<0 || j<0 )
                 L[i][j]=0;
               else if(word1[i]==word2[j])
                 L[i][j]=1+L[i-1][j-1];
               else
                 L[i][j]=max(L[i-1][j],L[i][j-1]);
           }
        cout << L[word1.size()-1][word2.size()-1] << endl;
    }
}