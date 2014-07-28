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
       //   freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,k,H,N,W,x,y;
      S(t);
      //int sub[205][2];
      int dp[605][605];
      while(t--)
      {

            S(W); S(H);
            S(N);
            for(i=0;i<=W;i++)
                for(j=0;j<=H;j++)
                    dp[i][j]=i*j;
            for(i=0;i<N;i++)
            {
                S(x); S(y);
                dp[x][y]=0;
            }

            for(i=0;i<=W;i++)
            {
                for(j=0;j<=H;j++)
                {
                  //  dp[i][j]=i*j;
                    for(k=0;k<=i;k++)// along width
                    {
                        dp[i][j]= min(dp[i][j], dp[k][j]+dp[i-k][j]);
                    }
                    for(k=0;k<=j;k++) // along height
                    {
                        dp[i][j]= min(dp[i][j], dp[i][k]+dp[i][j-k]);
                    }
                }
            }
            P(dp[W][H]);
      }
return 0;
}
