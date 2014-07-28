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
          freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,k,H,N,W;
      S(t);
      int sub[205][2];
      int dp[605][605];
      while(t--)
      {

            S(W); S(H);
            S(N);
             memset(dp,W*H+2,sizeof(dp));
            for(i=0;i<N;i++)
            {
                S(sub[i][0]); S(sub[i][1]);
                dp[sub[i][0]][sub[i][1]]=0;
            }

            for(i=1;i<=W;i++)
            {
                for(j=1;j<=H;j++)
                {
                    for(k=0;k<N;k++)
                    {
                        if(sub[k][0]<=i && sub[k][1]<=j)
                        {
                            dp[i][j]= min(dp[sub[k][0]][H-sub[k][1]]+ dp[ W- sub[k][0]][H],
                                          dp[W-sub[k][0]][sub[k][1]]+ dp[W][H-sub[k][1]] );

                        }
                    }
                }
            }
            P(dp[W][H]);
      }
return 0;
}
