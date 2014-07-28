// codeforces
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int dp[2][2002];
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);

    int n,x,y,i,selected,gap,j;
    S(n);
    int ar[n+5];

    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++) {S(ar[i]);  }
    int temp=1;
     for(gap=1;gap<=n;gap++)
     {
         selected=n+1-(gap);
         for(i=1,j=gap;j<=n;j++,i++)
         {

             if(i+1 <=j){
                 x=ar[i]*selected+dp[!temp][j];
                 //printf("dska\n");
             }
             else x=ar[i]*selected;
             if(i<=j-1){
                y= ar[j]*selected+  dp[temp][j-1];
                //printf("sajnj\n");
             }
             else y= ar[j]*selected;
             //printf("%d %d\n",x,y);
             dp[temp][j]= max( x,y);
             //if(i==1 && j==1)
               // printf("%d %d\n",dp[i][j],ar[i]);
         }
         temp=!temp;
     }
//     for(i=1;i<=n;i++)
//     {
//         for(j=i;j<=n;j++)
//         {
//             printf("%d ",dp[i][j]);
//         }
//         printf("\n");
//     }
     P(dp[!temp][n]);
return 0;
}
