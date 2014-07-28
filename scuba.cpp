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
int dp[1002][81][81];
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t;
      S(t);
      while(t--)
      {
         S(oxy); S(nit);
         S(N);
         int o[N+2], n[N+2],wt[N+2];
         for(i=1;i<=N;i++)
         {
             S(o[i]); S(n[i]); S(wt[i]);
         }
         memset(dp,0,sizeof(dp));
         for(i=1;i<=N;i++)
         {
             for(j=1;j<=oxy;j++)
             {
                 for(k=1;k<=nit;k++)
                 {
                     v1=j;
                     if(v1>=oxy) v1=oxy;
                     v2=k;
                     if(v2>=nit)v2=nit;
                     dp[i][j][k]= dp[i-1][j][k];

                     if(j-o[i]>=0)
                 }
             }
         }

      }
return 0;
}
