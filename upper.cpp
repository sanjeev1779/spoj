#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%ld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,N,M;
      S(t);
      while(t--)
      {
            S(N) S(M)
            int cost[N+2][M+2];
            for(i=1;i<=N;i++)
            {
                for(j=1;j<=M;j++) S(cost[i][j]);
            }
            int dp[N+2][M+2]; // dp[i][j] denotes maxm value till cell(i,j)
            memset(dp,0,sizeof(dp));
            for(i=1;i<=N;i++)
            {
                for(j=1;j<=M;j++)
                {
                    dp[i][j]= max(dp[i-1][j-1]+cost[i][j], max(dp[i-1][j]+cost[i][j], dp[i-1][j+1]+cost[i][j]));
                }
            }
            int ans=-1;
            for(j=1;j<=M;j++) ans= max(ans,dp[N][j]);
            P(ans);

      }
return 0;
}
