#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mem(arr,n) memset(arr,n,sizeof(arr)
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int cfreq[200003][102];
int recent[200003][102];
LL dp[200003][102];
int len[200003][102];
int ar[100005];
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,n;
      S(t);
      while(t--)
      {
          mem(cfreq,0);
          mem(recent,-1);
          mem(dp,0);
          mem(len,0);

            S(n);
            for(i=1;i<=n;i++)
            {
                 S(ar[i]);
                 recent[i][ar[i]]=i;
                 for(j=1;j<=100;j++)
                 {
                    if(ar[i]==j)
                    {
                        cfreq[i][j]= cfreq[i-1][j]+1;
                    }
                    else
                        cfreq[i][j]= cfreq[i-1][j];

                 }
            }

            for(i=1;i<=n;i++)
            {
                for(j=0;j<=200;j++)
                {
                    prev= ar[i]-j
                    dp[i][j]= dp[i-1][j];
                }
            }

      }
return 0;
}
