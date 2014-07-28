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
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
     int N,i,x,y,half,reqd;
     S(N);
     int top[100005], bot[100005];
     memset(top,0,sizeof(top));
     memset(bot,0,sizeof(bot));

    for(i=1;i<=N;i++)
     {
         S(x); S(y);
         top[x]++;
         if(x!=y)
            bot[y]++;
     }
     half= (N+1)/2;
     int ans=100005;
     for(i=0;i<=100000;i++)
     {
         reqd= half-top[i];
         if(reqd<=0) { reqd=0; ans=0; break;}
         else if(reqd<=bot[i])
         {
                ans= min(ans,reqd);
         }
     }
     if(ans==100005)
        printf("Impossible\n");
     else P(ans);
return 0;
}
