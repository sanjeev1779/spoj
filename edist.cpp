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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int dp[2005][2005];
main()
{
    int t,l1,l2,i,j;
    S(t);
    string str1,str2;
    while(t--)
    {
        cin>>str1>>str2;
        l1= str1.size();
        l2=str2.size();

        for(i=0;i<=l2;i++)
        {
            dp[0][i]=i;
        }
        for(i=0;i<=l1;i++)
        {
            dp[i][0]=i;
        }

        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]= dp[i-1][j-1];
                }
                else
                    dp[i][j]=min( min( dp[i-1][j]+1, dp[i][j-1]+1) , dp[i-1][j-1]+1 );
            }
        }
        cout<<dp[l1][l2]<<endl;
    }

return 0;
}
