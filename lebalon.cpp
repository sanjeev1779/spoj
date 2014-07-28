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
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,n,k,minmht;
      scanf("%d %d %d",&n,&k,&t);
      int ht[n+5];
      for(i=1;i<=n;i++) S(ht[i]);

      int dp[n+2][k+2]; // dp[i][j] denotes the maxm space till ith lot using at most j apartment
      memset(dp,0,sizeof(dp));
      int k1=k;
      for(i=1;i<=n;i++)
      {
          //printf("i=%d\n",i);
          for(j=1;j<=k1;j++)
          {
              dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
              minmht= INT_MAX;
              for(k=i;k>=1 && k>i-t;k--)
              {
                  minmht= min(minmht,ht[k]);
                  dp[i][j] = max( dp[i][j],  dp[k-1][j-1]+ (i-k+1)*minmht);
              }
             // P(dp[i][j]);
          }
      }
      P(dp[n][k1]);
return 0;
}
