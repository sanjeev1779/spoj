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
int digits(LL x)
{
    int cnt=0;
    while(x>0)
    {
        x/=10;
        cnt++;
    }
    return cnt;
}
LL make_num(int digit)
{
    LL num=1;
    while(digit>0)
    {
        num=num*10;
        digit--;
    }
    return num;

}
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
LL cal(LL x, int n)
{
    if(x==1)
        return 1;
    if(n==0) return 1;
    int dig= digits(x);
    int maxmd= 1+ (dig/n);
    LL high= make_num(maxmd);
    LL low=0,mid=0,root;
    cout<<"high= "<<high<<endl;

    while(low+1<high)
    {
        mid= low+ (high-low)/2;
        cout<<"high= "<<high<<" low= "<<low<<" mid= "<<mid<<endl;
        root= fastpow(mid,n);
        if(root==x)
            return mid;
        else if(root<x)
            low=mid+1;
        else high=mid;
    }
    return low;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int n,i,j,t;
      S(t);
      LL x;
      cout<<cal(2,33)<<endl;
      while(t--)
      {
            SL(x); //S(n);
            n=1;
            //LL ans= cal(x,n);
            while( cal(x,n)!=1)
            {
                n++;
            }
            cout<<n<<endl;
            for(int i=n;i<=10000;i++)
            {
                LL va=cal(x,i);

                if(va!=1)
                {
                    cout<<va<<" and i ="<<i<<endl;
                    printf("unmatched\n"); break;
                }
            }


      }
return 0;
}
