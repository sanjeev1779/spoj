#include<bits/stdc++.h>
using namespace std;
#define LL long long int
LL ar[10005],cumsum[10005],a;
LL mod=1000000007;
LL sum=0,v;
int n,q,i;
int minm(int a,int b) {if(a>b) return b; return a;}
void solve()
{

    scanf("%d %d",&n,&q);
    int limit= minm(n,65);
    cumsum[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&ar[i]);
        if(ar[i]<0)
            ar[i]=(ar[i]+mod)%mod;
        cumsum[i]= (cumsum[i-1]+ar[i])%mod;
    }
    double r;

//    if(n>65)
//    {
//        scanf("%lld",&a);
//        if(a<0)a=(a+mod)%mod;
//        sum=(sum+a)%mod;
//    }
    LL ans=0,x,y;
    while(q--)
    {
        scanf("%lld",&x);

        limit= minm(n,65);
        y=x%mod;
         ans= (y*ar[1]);
         if(ans>=mod)
            ans%=mod;
        int root1=0;
        for(i=2;i<=n;i++)
        {
            r= pow(10.0000, (double)(log10(x)/(double)(i)));
            v= (LL) (r);
            if(v>=mod)v=v%mod;
            if(v==1)
            {
                root1=1;
                break;
            }
            v=(v*ar[i]);
            if(v>=mod)v=v%mod;
            ans= (ans+v)%mod;
        }
        if(root1==1 && i<=n)
        {
            ans= (ans+cumsum[n]-cumsum[i-1]+mod)%mod;
        }
        printf("%lld ",ans);
    }
    printf("\n");
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
