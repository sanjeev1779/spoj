#include<iostream>
#include<stdio.h>
#include<algorithm>
#define LL long long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
using namespace std;
main()
{

      int i,j,t,N;
      LL sum,a[10005],left,avg,ans;
      S(t);
      while(t--)
      {
            S(N); sum=0,ans=0;
            LL pre[10005]; pre[0]=0;
            for(i=1;i<=N;i++)
            {
                SL(a[i]);
                sum+=a[i];
                pre[i]= pre[i-1]+a[i];
            }
            avg= sum/N;
            if(avg>a[1])
            {
                ans= a[1]; left=0;
            }
            else
            {
                ans=avg;
                left= a[1]-avg;
            }
            for(i=2;i<=N;i++)
            {
                a[i]= a[i]+left;
                     if(ans>a[i])
                    {
                        ans= a[i]; left=pre[i-1]-(ans-a[i])*(i-1);
                    }
                    else
                    {
                        ans=ans;
                        left= a[i]-ans;
                    }
            }
            printf("%lld\n",ans);
      }
return 0;
}
