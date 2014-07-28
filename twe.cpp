#include<cstdio>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<cstdlib>

using namespace std;
#define ll long long int

#define MX 1005
int dp[MX][MX];
int a[MX];

int getdp(int  i ,int  j){
    if( i>j ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];

    int sum1, sum2;
    // i-th is taken
    if( a[i+1] >= a[j] )     sum1 = a[i] + getdp(i+2,j); //greedy checking of 2 player
    else if( a[i+1] <a[j] )  sum1 = a[i] + getdp(i+1,j-1);

    //j-th is taken
    if( a[i] >= a[j-1] ) sum2 = a[j] + getdp( i+1 , j-1);//greedy checking of 2 player
    else if( a[i] < a[j-1] )  sum2 = a[j] + getdp ( i , j-2 );

    dp[i][j] = sum1>sum2?sum1:sum2;
    return dp[i][j];
}
int main(){
  int i,j,k,n,t;
  t= 0;
  int sum;
  while( 1 ) {
        t++;
        scanf("%d",&n);
        if( n == 0) break;
        sum = 0;
        for( i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum += a[i];
        }
        for(j=0;j<=n;j++){
            for(i=0;i<=j;i++){
                dp[i][j] =  -1;
            }
        }
        for( i=0;i<n;i++){
            dp[i][i] = a[i];
        }
        int p1 = getdp(0,n-1);
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++) cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        int p2 = sum - p1;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", t, p1-p2 );
  }
  return 0;
}
