// codeforces
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int n,i,j;
        cin>>n;
        int a[12];
         int dp[12];
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            dp[i]=1;
        }


        int maxm=-1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if(a[i]>a[j] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            maxm= max(maxm,dp[i]);
        }
      //  for(i=1;i<=n;i++) cout<<dp[i]<<" ";
        cout<<maxm<<endl;

return 0;
}
