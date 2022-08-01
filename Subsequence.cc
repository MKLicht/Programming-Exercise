#include<queue>
#include<iostream>
using namespace std;

int main()
{
    int K,N,S,num;
     queue<int> Q;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        int sum=0;
        int count=0;
        int min=100000000;
        int flag=0;
        scanf("%d%d",&N,&S);
        for(int j=0;j<N;j++)
        {
            scanf("%d",&num);
            Q.push(num);
            sum+=num;
            count++;
            if(sum>=S)
            {
                flag=1;  /*合計がSに超える場合があったら、結果が0にならないので、flagが1にセットします。*/
                do
                {
                   int n=Q.front();
                   Q.pop();
                   sum-=n;
                   count--;
                }while(sum>=S);
                count++;　　　/*ループするとき、合計がSより小さくなるまで止まらないので、数を一つ多く増やす必要はあります。*/
                if(count<min)
                  min=count;
                count--;　/*先増やしましたけど、実際その要素はもうpopしました。minと比較したあと減らします。*/
            }
        }
        if(!flag)
          min=0;
        cout << min << endl;
        while(!Q.empty())
             Q.pop();
    }
}