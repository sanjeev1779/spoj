
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
      int i,j,x,K;
      S(x);
      S(K);
      int coins[7];
      int sum[7];
      sum[0]=0;
      for(i=1;i<=K;i++)
      {
          S(coins[i]);
         sum[i]= sum[i-1]+coins[i];
      }
      bool dp[x+2][7];
      for(i=1;i<=x;i++) dp[i][0]= false; // i ruppes uisng 0 coins
      for(i=0;i<=K;i++) dp[0][i]=true; // 0 rupees using i coins

      for(i=1;i<=x;i++)
      {
          for(j=1;j<=K;j++)
          {
              dp[i][j]= dp[i][j-1]; // not take
              if(i>=sum[j])// if we take this coin jth coin
                dp[i][j]= dp[i][j-1] | dp[i-sum[j]][j-1];
          }
      }
       if(dp[x][K])
          printf("YES\n");
       else printf("NO\n");
return 0;
}
