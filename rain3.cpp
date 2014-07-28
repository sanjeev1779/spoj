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
vector<LL>prefix;

int bs(int left,int right, LL num)
{
    int mid= left+ (right-left)/2;
    while(left<right)
    {
        if(prefix[mid]==num)return mid;

        if(prefix[mid-1]<num && num<prefix[mid]) return mid-1;
        else if(prefix[mid]>num)
        {
            right= mid-1;
        }
        else
            left= mid+1;
    }
    return -1;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,n,test;
      S(test);
      LL te,ans,x;
      LL s,t,m,a,sum;
      while(test--)
      {
         scanf("%lld %lld %d %lld",&s,&t,&n,&m);

         te= (s%100+1)*(t%100+1);
        // P(te);
         prefix.pb(0);
        // printf("%d %d\n",s,t);
         for(i=1;i<=n;i++)
         {
             s = (78901 + 31*s)%699037;
             t = (23456 + 64*t)%2097151;
            // printf("%lld %lld\n",s,t);
             a= (s%100+1)*(t%100+1);
             //P(a);
            // printf("%d ",a);
             te= prefix[i-1]+a;
             prefix.pb(te);
         }
         LL rem;
         //cout<<endl;
         //for(i=1;i<=n;i++) printf("%lld ",prefix[i]);
         //cout<<endl;
         ans= INT_MAX;
         for(i=1;i<=n;i++)
         {
             sum= prefix[i-1]+m;
             rem= prefix[n]-prefix[i-1]; // sum from i to n
             if(rem<= m)
             {
                    x= n-i+1;ans= min(ans, x); break;
             }
             if(prefix[i]-prefix[i-1] >m){ ans=0; break;}

            //   x=upper_bound(prefix.begin(),prefix.end(),sum)- lower_bound(prefix.begin(),prefix.end(),-1);
              //  printf("before i=%d, x= %d\n",i,x);
            //  if(x<=i)x=i;
            x= bs(i,n,sum);
                x= (x-i+1);

            // printf("sum= %lld, x=  %d \n\n",sum,x);
             ans= min(ans, x);
         }
         printf("%lld\n",ans);
      }
return 0;
}
