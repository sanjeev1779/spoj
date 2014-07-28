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
int dp[102][102];
int main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int N,x,t,i;
      vector<int>vec;
      S(N)
      for(i=0;i<N;i++)
      {
          S(x); vec.pb(x);
      }

      S(t);
      while(t--)
      {
          S(x);
          int ans= upper_bound(vec.begin(),vec.end(),x)- lower_bound(vec.begin(),vec.end(),-1);
          P(ans)
      }
return 0;
}
