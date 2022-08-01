#include<iostream>
using namespace std;

int a[100001], lis[100001];

void bsearch(int n,int len)
{
    int left=1;
    int right=len;
    while(left<=right)
    {
        int med=(left+right)/2;
        if(lis[med]>=n)  right=med-1;
        else left=med+1;
    }
    lis[left]=n;
}
int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
       cin >> a[i];
    int len=1;
    lis[len]=a[0];
    for(int i=1;i<N;i++)
    {
        if(lis[len]<a[i])
        {
            len++;
            lis[len]=a[i];
        }
        else
           bsearch(a[i],len);
    }
    cout << len << endl;
}