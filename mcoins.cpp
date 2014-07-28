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
bool dp[1000005]; // dp[false] means losing position, true is winning pos.
void precompute(int K,int L)
{
    dp[0]= false;
    for(int i=1;i<=1000000;i++)
    {
        if(dp[i-1]==false)// taking one
        {
            dp[i]= true; continue;
        }
        else if(i-K>=0 && dp[i-K]== false)// taking K
        {
            dp[i]= true; continue;
        }
        else if(i-L>=0 && dp[i-L]== false)// taking K
        {
            dp[i]= true; continue;
        }
        else dp[i]=false;
    }
    return;
}

int main()
{
          //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,K,L,M,x;
      S(K); S(L); S(M);
      precompute(K,L);
      for(i=1;i<=M;i++)
      {
          S(x);
          if(dp[x]) printf("A");
          else printf("B");
      }
return 0;
}
