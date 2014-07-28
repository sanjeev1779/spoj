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
main()
{
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int test,finish_max,start_min,i,x,y,z,maxm,ans,j,K,M;
    S(test);
    int freq[32];
    int time[32][2];
    for(int zz=1;zz<=test;zz++)
    {
        S(K); S(M);
        start_min= INT_MAX;
        finish_max= INT_MIN;
        memset(freq,0,sizeof(freq));
        for(i=1;i<=K;i++)
        {
            S(time[i][0]); S(time[i][1]);
            start_min= min(start_min,time[i][0]);
            finish_max= max(finish_max,time[i][1]);
        }
        while(M--)
        {
            S(x);
            for(i=1;i<=x;i++)
            {
                S(y); S(z);
                freq[y]+=z;
            }
        }

        maxm= INT_MIN;
       // cout<<start_min<<"  "<<finish_max<<endl;
        for(i=start_min;i<=finish_max;i++)
        {
            ans=0;
            for(j=1;j<=K;j++)
            {
                if(time[j][0]<=i && time[j][1]>=i)
                {
                  //  cout<<" j "<<j<<endl;
                    ans+= freq[j];
                }
            }
          //  cout<<" ans ="<<ans<<endl;
            maxm= max(maxm, ans);
        }
        printf("Case %d: %d\n",zz,maxm);

    }

return 0;
}
