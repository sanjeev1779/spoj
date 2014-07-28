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
#define S(N) scanf("%d",&N)
#define SL(N) scanf("%ld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,n,x1,y1,k;
      int cards[1005];
      int kt=0;
      while(S(n)>0 && n!=0)
      {
          kt++;
          int sum=0;
        for(i=1;i<=n;i++) {  S(cards[i]);  sum+=cards[i];}
        int dp[n+5][n+5];
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++) dp[i][i]= cards[i];
        int flag1,flag2,flag3,flag4;

        for(k=1;k<=n;k++)
        {

            for(j=k,i=1;j<=n;i++,j++)
            {
                 flag1=flag2=flag3=flag4=0;
                // first user chose ith card
                if(i+1 <=j && cards[i+1]>=cards[j]) // 2nd chose i+1th card
                {
                    x1= cards[i];//+ (i+2<=j)?dp[i+2][j]:0; flag1=1;
                      if(i<=j-2) x1+= dp[i+2][j];
                    //printf(" i and i+1,x1=%d ,cards= %d \t ",x1,cards[i]);
                }
                else // 2nd chose jth card
                {
                     x1= cards[i];//+ (i+1<=j-1)?dp[i+1][j-1]:0; flag2=1;
                     if(i<=j-2) x1+= dp[i+1][j-1];
                    //  printf(" i and j,x1=%d,cards= %d \t ",x1,cards[i]);
                }

                // first user chose jth card
                if(i+1 <=j && cards[i]>=cards[j-1]) // 2nd chose ith card
                {
                    y1= cards[j];//+ (i+2<=j)?dp[i+1][j-1]:0; flag3=1;
                     if(i<=j-2) y1+= dp[i+1][j-1];
                    // printf(" j and i,y1=%d,cards= %d\t ",y1,cards[j]);
                }
                else // 2nd chose (j-1)th card
                {
                     y1= cards[j];//(i+1<=j-1)?dp[i][j-2]:0; flag4=1;
                       if(i<=j-2) y1+= dp[i][j-2];
                   //  printf(" j and j-1,y1=%d,cards= %d \t ",y1,cards[j]);
                }
                dp[i][j]= max(x1,y1);
                //printf("\n");
            }
        }
        int ans= 2* dp[1][n]-sum; // first= dp[1][n], 2nd= sum-dp[1][n]; diff= first-second;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",kt,ans);
     }
return 0;
}
