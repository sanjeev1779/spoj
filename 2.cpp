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
        int n,k,x;
        cin>>n>>k>>x;
        int i,j,l;
        vector<int>vec,temp;
        for(i=1;i<=n;i++)
        {
            S(y);
           vec.pb(y);
        }
        temp=vec;
        int vis[108];
        memset(vis,0,sizeof(vis));
             for(i=1;i<=n;i++)
             {
                 memset(vis,0,sizeof(vis));
                 if(arr[i]==x)
                 {
                    cnt=0;
                    flag=1;
                    for(;i<=n;i++)
                    {
                        if(arr[i]==x)
                        {
                            cnt++;
                        }
                    }
                    if(cnt>=2)
                    {
                        //
                        ans+= cnt;
                        while(1)
                        {
                            cnt=0;
                            for(j=i-1;j>=0;j--)
                            {
                                if(arr[j]==x)
                                {
                                    vis[j]=1;// not present
                                }
                            }

                                cnt=0;
                                for(j=1;j<=n;j++)
                                {
                                    if(vis[j]==1) j++;
                                    else
                                    {
                                        last=arr[j];
                                        for(;j<=n;j++)
                                        {
                                                if(vis[j])j++;
                                        }

                                    }
                                }
                                if(cnt<)
                            }
                        }
                    }
                 }
             }

return 0;
}
