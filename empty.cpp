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
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int dp[1005];
void precompute()
{
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=1000;i++)
    {
        int ans=10005;
        int x= sqrt(i);
        if(x*x==i) ans=1;
        else
        {
            for(int j=1;j<i;j++)
            {
                ans= min(ans,dp[j]+dp[i-j]);
         //      if(i==106) printf("%d %d\n",j,ans);
            }
        }
        dp[i]= ans;
    }
}
main()
{

    int t,A;

    precompute();
    S(t);
    while(t--)
    {
        S(A);
        P(dp[A]);
    }
return 0;
}
