#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define ULL unsigned long long
#define LL long long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
LL mod= 10e9+7;
 LL ar[10004];
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
LL upperbound[]={1000000, 31623, 3982, 1000, 373, 178, 100, 64, 44, 32, 25, 20, 16, 14, 12, 10, 9, 8, 8, 7};// right maxium
LL fastpow(LL a, int b)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2==1)
            prod=(prod*a);
        a=(a*a);
        b=b/2;
    }
    return prod;
}
int length(LL i, int n)
{
    double dig= n*log10(i);
    return ceil(dig);
}

LL largeroot(LL x, int n)
{
        // check for each i from 1 to at maxm 7
        LL i=1;
        int dig;
        LL root1,root2;
        for(i=1;i<=8;i++)
        {
            root1= fastpow(i,n); // no overflow
            dig= length(i+1,n);
            if(dig>19)// overflow
            {
                return i;
            }
            root2= fastpow(i+1,n);

            if(root1== x || root1<x && x<root2) return i;
        }
    return -1;
}
LL cal(LL x,int n)
{
    LL ans;
    if(n==0 || x==1) return 1;
    if(n==1) return x;
    if(n==2) { ans= sqrt(x); return ans;}

    if(n>=23)
    {
        return largeroot(x,n);
    }
    LL root1,root2,root;
    LL right= upperbound[n-3]-1;
    LL left=1,mid=0;

    while(left<=right)
    {
        mid= left+ (right-left)/2;
        root1= fastpow(mid,n);
        root2= fastpow(mid+1,n);
       // printf("left=%lld right=%lld mid=%lld root1=%lld root2=%lld\n",left,right,mid,root1,root2);
        if(root1==x || (root1<x && x<root2)) return mid;
        else if(root1>x) right= mid-1;
        else left= mid+1;
    }
    return 1;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,N,Q;
      bool stop;
      S(t);
      LL val,x,extra,temp,finally;
      LL sum[10005],root;
      while(t--)
      {
          S(N); S(Q);
          sum[0]=0;
          for(i=1;i<=N;i++)
          {
                scanf("%lld",&ar[i]);
                if(ar[i]<0)
                    ar[i]= (ar[i]+mod)%mod;
                sum[i]= (sum[i-1]+ ar[i])%mod;
          }

          while(Q--)
          {
              scanf("%lld",&x);
              val=0;
              stop=false;
              extra=0;
         //     int upto= min(N,64);
              for(i=1;i<=N;i++)
              {
                    root= cal(x,i);

                    root= (root%mod);
                    temp= (root*ar[i])%mod;
                  val= (val+temp+mod)%mod;
                  //  cout<<root <<" "<<temp<<endl;
                    if(root==1)
                    {
                        stop=true; break;
                    }
              }
              if(stop==true && (i+1)<=N)// extra sum left from (i+1) to N
              //if(N>64)
              {
                  extra= (sum[N]-sum[i] + mod)%mod;
              }
              finally= (val+extra+mod)%mod;
              printf("%lld ",finally);
          }
         printf("\n");
          //cout<<mod<<endl;
      }
return 0;
}
