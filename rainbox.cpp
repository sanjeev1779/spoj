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
bool vis[1005];
int wt[1005];
int nodes=0,comp_wt=0;
vector<int>adj[1005];
void dfs(int x)
{
//    printf("%d ",x);
    nodes++;
    int nod;
    comp_wt+= wt[x];

    vis[x]=true;

    for(int i=0;i<adj[x].size();i++)
    {
        nod= adj[x][i];
        if(vis[nod]==false)
        {
            dfs(nod);
        }
    }
    return;
}
main()
{
        // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,N,C,si,x;

      while(1)
      {
          int data[1005][2];
            S(N); S(C);
            if(N==0 && C==0) break;
            for(i=0;i<=1000;i++)
                adj[i].clear();
            memset(vis,false,sizeof(vis));

            for(i=1;i<=N;i++)
                S(wt[i]);

            for(i=1;i<=N;i++)
            {
                S(si);
                while(si--)
                {
                    S(x);
                    adj[i].pb(x);
                    adj[x].pb(i);
                }
            }
            int cmp=1;
            for(i=1;i<=N;i++)
            {
                if(vis[i]==false)
                {
                    nodes=0; comp_wt=0;
                    //printf("Nodes :: ");
                    dfs(i);
                    //printf("\n");
                    data[cmp][0]= nodes; data[cmp][1]= comp_wt;
                    cmp++;
                }
            }

            // knapsack
            int dp[2][C+5];
            int temp=1;
            for(i=0;i<=C;i++)
            {
                dp[temp][i]= dp[!temp][i]=0;
            }
            for(i=1;i<cmp;i++)
            {
                for(j=1;j<=C;j++)
                {
                    dp[temp][j]= dp[!temp][j];
                    if(j>= data[i][1])
                    {
                        dp[temp][j]= max( dp[temp][j], dp[!temp][j-data[i][1]]+ data[i][0]);
                    }
                }
                temp=!temp;
            }
            P(dp[!temp][C]);
      }
return 0;
}
