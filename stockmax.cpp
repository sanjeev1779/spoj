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
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%ld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,n,maxm;
      S(t);
      while(t--)
      {
            S(n);
            int Arr[n+5];
            for(i=1;i<=n;i++)
            {
                S(Arr[i]);
            }
            LL sum=0;
            maxm=Arr[n];
            for(i=n-1;i>=1;i--)
            {
                if(Arr[i]< maxm) sum+= (maxm-Arr[i]);
               if(Arr[i]>maxm)
               {
                   maxm= Arr[i];
               }

            }
            cout<<sum<<endl;
      }
return 0;
}
