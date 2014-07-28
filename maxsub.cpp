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
LL mod=1000000009;
LL fast(LL a, int b)
{
    LL prod=1;
    while(b>0)
    {
        if(b&1)prod=(prod*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return prod;
}

main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,t,n;
      LL x,ans;
      S(t);
      while(t--)
      {
          ans=0;
          LL cnt=0;
          int pos=0;
          LL maxm= -1000000007;
          S(n);
          int zero=0;
          for(i=1;i<=n;i++)
          {
              SL(x);
              if(x>0)
              {
                  pos=1;
                  ans=(ans+x);
              }
              if(x>maxm)
              {
                    maxm=x; cnt=0;
              }
              if(x==maxm)
                cnt++;
              if(x==0) zero++;
          }
          if(pos)
            {
                cnt= fast(2,zero);
                //P(zero);
                printf("%lld %lld\n",ans,cnt);
            }
          else {
              if(maxm==0) cnt= fast(2,zero)-1;
            printf("%lld %lld\n",maxm,cnt);
          }
      }
return 0;
}

