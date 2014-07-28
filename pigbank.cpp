#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
 int dp[505][10005];
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int e,f,W,i,n,j,t;
      S(t);
      int val[505],wt[505];
      int maxm= 10000000;
      while(t--)
      {
          S(e) S(f);
          W=f-e;
          S(n);
          for(i=1;i<=n;i++)
          {
              S(val[i]); S(wt[i]);
          }

          for(i=0;i<=n;i++)dp[i][0]=0;

          for(i=1;i<=n;i++) // each item 1 to N
          {
              for(j=1;j<=W;j++)// for each wt 1 to W
              {
                  if(i==1 && j<wt[1])//only one item
                  {
                      dp[1][j]=maxm; // cant take
                  }
                  else if(i==1)
                  {
                      dp[1][j]= val[1]+dp[1][j-wt[1]];
                  }
                  else if(j<wt[i]) dp[i][j]= dp[i-1][j]; // dont' take
                  else dp[i][j]= min( dp[i-1][j],val[i]+dp[i][j-wt[i]]);
              }
          }
          if(dp[n][W]>=maxm)
            printf("This is impossible.\n");
          else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[n][W]);
      }
return 0;
}
