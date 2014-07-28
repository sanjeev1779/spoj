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
    int t,i,j,n;
    S(t);
    while(t--)
    {
        S(n);
        LL arr[n+2];
        int ans=0;
        int vis[n+2]; memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++) SL(arr[i]);
        sort(arr,arr+n);
        for(i=0;i<n;i++)
        {
            if(vis[i]==1) continue;
            for(j=0;j<n;j++)
            {
                if(vis[j]==0 && arr[j]==2*arr[i])
                {
                    ans++; vis[j]=vis[i]=1; break;
                }
            }
        }
        P(ans);
    }
return 0;
}
