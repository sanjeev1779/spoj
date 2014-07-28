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
      string str1,str2;
      int i,j,l1,l2;
      cin>>str1>>str2;
       l1=str1.size();
       l2=str2.size();

      int dp[l1+2][l2+2];
      for(i=0;i<=l1;i++)
      {
          for(j=0;j<=l2;j++)
          {
              if(i==0 || j==0) dp[i][j]=0;
              else if(str1[i-1]!=str2[j-1]) dp[i][j]= dp[i-1][j-1]+1;
              else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
              cout<<dp[i][j]<<" ";
          }
          cout<<endl;
      }
      P(dp[l1][l2]);
return 0;
}
