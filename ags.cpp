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

LL pow1(LL a,LL b,LL mod)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2) prod= (prod*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return prod;
}
LL inv(LL a, LL mod)
{
    return pow1(a,mod-2,mod);
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    LL a,d,r,n,mod,ans,x;
    int t;
    S(t);
    while(t--)
    {

        scanf("%lld %lld %lld %lld %lld",&a,&d,&r,&n,&mod);
        if(n&1)
        {
            x=n>>1;
            ans= ((a* pow1(r,x,mod) )%mod + (((d*r)%mod)* (((pow1(r,x,mod)-1)*inv(r-1,mod))%mod))%mod )%mod;
        }
        else
        {
             x=n/2-1;
             ans= (a* pow1(r,x,mod) + mod)%mod;
         //    P(ans);
           //  P(pow1(r,x+1,mod)-1);
             ans+=((d%mod)* (((pow1(r,x+1,mod)-1)*inv(r-1,mod) + mod)%mod)+ mod)%mod;
             //P(ans);
             ans%=mod;
        }
        printf("%lld\n",ans);
    }
return 0;
}
