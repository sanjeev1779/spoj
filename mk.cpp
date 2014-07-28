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

        //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int x,i,j,t,cur,next;
      string str;
      cin>>str;
      int l= str.size();
      int dp[l+5];// stores minm till i
      for(i=0;i<=l+1;i++) dp[i]=l+5; // intialized to maxm
      int same[12];
      for(i=0;i<10;i++) same[i]=l+5;// intialized to maxm

      dp[0]=0; // 0 based index
      same[str[0]-'0']=0;

    //1st loop from left to right
      for(i=1;i<l;i++)
      {
          cur= str[i]-'0';
         // next= str[i]-'0';
          dp[i]= min(dp[i-1]+1, same[cur]+1);
          same[cur]= min(same[cur],dp[i]);// same stores minm to reach cur th digit
      }
//      for(i=0;i<l;i++) printf("%d ",dp[i]);
//      printf("\n");

      // 2nd looop from right to left
      for(i=l-2;i>=0;i--)
      {
           cur= str[i]-'0';
            dp[i]= min(dp[i], min(dp[i+1]+1, same[cur]+1));
             same[cur]= min(same[cur],dp[i]);// same stores minm to reach cur th digit
      }
//      for(i=0;i<l;i++) printf("%d ",dp[i]);
//      printf("\n");
      //now combine above two to get minm from both sidess
      for(i=1;i<=l-2;i++) // last index l-1 is left
      {
            cur= str[i]-'0';
          dp[i]= min(same[cur]+1, min(dp[i-1]+1,dp[i+1]+1));
      }
      // for last index
      if(l>=2)dp[l-1]= min(dp[l-2]+1, same[str[l-1]-'0']+1);


//      for(i=0;i<l;i++) printf("%d ",dp[i]);
//      printf("\n");
      P(dp[l-1])
return 0;
}
