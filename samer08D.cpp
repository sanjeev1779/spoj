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
main()
{
         freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int K,l1,cnt,l2,i,j;
      string str1,str2;
      while(1)
      {
          cin>>K;
          if(K==0)
            break;
          cin>>str1>>str2;
          l1= str1.length();
          l2= str2.length();
          int dp[l1+5][l2+5];
          memset(dp,0,sizeof(dp));
          cnt=0;
          for(i=1;i<=l1;i++)
          {
              for(j=1;j<=l2;j++)
              {

              }
          }
          cout<<dp[l1][l2]<<endl;
      }


return 0;
}
