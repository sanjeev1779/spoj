#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<stack>
#include<math.h>
#include<algorithm>
#define LL long long
#define LI long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int ht[1005][1005];

int histogram(int N, int M)
{
    stack<int>st;
    int j=0;
    int top;
    int cur_area,max_area=0;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {

        }
    }
}
main()
{
//          freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int Q,i,N,M,j;
      int x;
      int ans;
      S(N); S(M);
           // for(i=0;i<N;i++) for(j=0;j<M;j++) scanf("%c",area[i][j]);
            ans=0;
            memset(ht,0,sizeof(ht));
            for(i=1;i<=N;i++)
            {
                for(j=1;j<=M;j++)
                {

                    scanf("%d",&x);
                        if(x==0) ht[i][j]=ht[i-1][j]+1;
                        else ht[i][j]=0;
                }
            }
            histogram(N,M);// find the width for each index


      }
return 0;
}
