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
 int l[1003][1003];
 int rt[1003][1003];
 int height[1003][1003];
main()
{
        //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);

     int test_cases,i,j,N,M,area,cur_area;
     char ch;
     S(test_cases);
     while(test_cases--)
     {

         S(N);S(M);
         memset(height,0,sizeof(height));
         memset(l,0,sizeof(l));
         memset(rt,0,sizeof(rt));
         int a[N+2][M+2];
         for(i=1;i<=N;i++)
         {
             for(j=1;j<=M;j++)
             {
                 cin>>ch;
                 if(ch=='R')
                    a[i][j]=0;
                 else a[i][j]=1;
             }
         }
         for(i=1;i<=N;i++)
         {
             for(j=1;j<=M;j++)
             {
                 if(a[i][j]) // if free
                    height[i][j]= height[i-1][j]+1;
                else height[i][j]=0;
             }
         }

         for(i=1;i<=N;i++)
         {
             for(j=1;j<=M;j++)
             {
                if(a[i][j]==0)
                    l[i][j]=0;
                else if(height[i][j-1]<height[i][j])
                    l[i][j]=1;
                else l[i][j]= l[i][j-1]+1;
             }
         }
         for(i=1;i<=N;i++)
         {
             for(j=M;j>=1;j--)
             {
                 if( a[i][j]=0)
                    rt[i][j]=0;
                else if(height[i][j]> height[i][j+1])
                    rt[i][j]=1;
                 else rt[i][j]= rt[i][j+1]+1;
             }
         }
         area= -1;
         for(i=1;i<=N;i++)
         {
             for(j=1;j<=M;j++)
             {
                cur_area= height[i][j]*( l[i][j]+ rt[i][j]-1);
                area= max(area, cur_area);
             }
         }
         area= 3*area;
         printf("%d\n",area);

     }
return 0;
}

