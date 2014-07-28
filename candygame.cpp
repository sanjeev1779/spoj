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
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t;
      S(t);
      LL ar[53][53];
      LL dp[53][53][53][53];
      LL srow[53][53], scol[53][53];
      while(t--)
      {
        S(N); S(M);
        memset(srow,0,sizeof(srow));
        memset(scol,0,sizeof(scol));
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                 SL(ar[i][j]);
                 srow[i][j]=  srow[i][j-1]+ar[i][j];
            }
        }
        for(i=1;i<=M;i++)
        {
            for(j=1;j<=N;j++)
            {
                scol[i][j]= scol[i][j-1]+ar[i][j];
            }
        }

        memset(dp,0,sizeof(dp));

        for(row=1;row<=N;row++)
        {
            for(col=1;col<=M;col++)
            {
                for(i=1,j=row;j<=N;i++,j++)
                {
                    for(k=1,l=col;l<=M;k++,l++)
                    {
                         // if ith row is selected,
                         si= (k==0? (srow[i][l]):(srow[i][l]-srow[i][k-1]));

                         if(i==j)
                            dp[i][j][k][l]= si;
                         else
                         {

                         }
                    }
                }
            }
        }

      }
return 0;
}
