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
      for(i=0;i<=l+1;i++) dp[i]=l+5;
      int same[12];
      for(i=0;i<10;i++) same[i]=l+5;

      dp[1]=0; // 1 based index
      same[str[0]-'0']=0;

      for(i=2;i<l;i++)
      {
          cur= str[i-1]-'0';
          next= str[i]-'0';
          dp[i]= min( same[next]+2, min(dp[i-1]+1, same[cur]+1)); // sam[next]+2 from right
          same[cur]= min(same[cur],dp[i]);// same stores minm to reach cur th digit
      }
      if(l>1)dp[l]= min(dp[l-1]+1, same[str[l-1]-'0']+1);
      P(dp[l])
return 0;
}
