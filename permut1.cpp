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
int dp[13][100];
int calc(int n,int k)
{
    if(n==0)return 0;
    if(k==0)return 1;

    if(dp[n][k]!=-1) return dp[n][k];

    int sum=0;
    for(int i=0;i<n &&(k-i)>=0; i++)
        sum+=calc(n-1,k-i);
    return (dp[n][k]=sum);
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,n,k;
      S(t);
      while(t--)
      {
          memset(dp,-1,sizeof(dp));
            S(n); S(k);
            cout<<calc(n,k)<<endl;
      }
return 0;
}
