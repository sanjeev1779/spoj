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


int main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      LL i,j,n;
      LL test;
      SL(test);
      LL te,ans,x;
      LL s,t,m,a,sum;
      while(test--)
      {
         cin>>s>>t>>n>>m;
        vector<LL>prefix;
        prefix.assign(n+1,0);
        // te= (s%100+1)*(t%100+1);
        // P(te);
       //  prefix.pb(0);
         ans= INT_MAX;
        // printf("%d %d\n",s,t);
         for(i=1;i<=n;i++)
         {
             s = (78901 + 31*s)%699037;
             t = (23456 + 64*t)%2097151;
            // printf("%lld %lld\n",s,t);
             a= (s%100+1)*(t%100+1);
             //P(a);
           //  printf("%d ",a);
        //   if(a>m) ans=0;

             te= prefix[i-1]+a;
             prefix.pb(te);
         }
         //if(ans==0) { cout<<"0\n"; continue;}//impossible
         LL rem;
        // cout<<endl;
         //for(i=1;i<=n;i++) printf("%lld ",prefix[i]);
         //cout<<endl;
        ans= INT_MAX;
         LL siz=0;
         LL left=1,right=2;
         while(left<=n && right<=n)
         {
             if( (prefix[right]-prefix[left-1]) <=m) right++; // extend the sub array towards right
             else
             {
                 siz= right-left;
                 ans= min(ans,siz);
                 left++;
             }
         }
         if(ans==INT_MAX) ans=0;
         printf("%lld\n",ans);
      }
return 0;
}
