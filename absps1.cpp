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
main()
{
          freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int t,i,j,n,m;
    S(t);
    string str;
    int dp[105][105];
    char adj[105][104];
    while(t--)
    {
        S(m); S(n);
        int inf= -10010;
        for(i=1;i<=n;i++)
        {
            cin>>str;
            for(j=1;j<=m;j++)
                adj[i][j]=str[j-1];
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(adj[i][j]=='*')
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
                else if(adj[i][j]=='.')
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                else dp[i][j]=inf;
            }
        }
       /* for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/

        P(dp[n][m]);
    }
return 0;
}
