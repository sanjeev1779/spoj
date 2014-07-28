#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%ld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
bool prime[100015];
vector<int>dp;
int bin(int num,int left,int right)
{
    while(left<=right)
    {
        int mid= left+ (right-left)/2;
        if(dp[mid]==num)
        {
            while(dp[mid]==num) mid--;
            mid++;
            return mid;

        }
        else if(dp[mid-1]< num && dp[mid]>num) return mid;

        else if(dp[mid]>num) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
void sieve()
{
    int N=100005,x;
    dp.pb(0);
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    x= sqrt(N);
    for(int i=2;i<=x;i++)
    {
        if(prime[i]==true)
           		for(int j=i+i; j<N; j+=i) prime[j] = false;

    }
    for(int i=1;i<=N;i++)
    {
        x= (prime[i]==true)?(dp[i-1]+1):dp[i-1];
        dp.pb(x);
    }
    return;
}
main()
{
          freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      sieve();
      int i,j,t,N,K,p,x,bi;
      S(t);
      while(t--)
      {
            S(N); S(K);
           // for(i=0;i<=N;i++) cout<<dp[i]<<" ";
        //    cout<<endl;
            LL ans=0;
            for(i=2;i<=N;i++)
            {
                p= dp[i-1]+K;

                x= bin(p,1,N);
             //    printf("val = i=%d x=%d ::::::: , p=%d\n ",i,x,p);
                if(x==-1)break;
                ans+=(N-x+1);
            }
            cout<<ans<<endl;
      }
return 0;
}
