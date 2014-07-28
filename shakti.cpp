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
long int a[100005];
int bs(long int x,int N)
{
    int start=0, en=N-1,mid;
    while(start<=en)
    {
        mid= start+ (en-start)/2;
        if(a[mid]==x)
        {
            while( mid>=0 && a[mid]==x )
            {
                mid--;
            }
            mid++;
            return mid;
        }
        else if(a[mid]<x)
            start=mid+1;
        else en=mid-1;
    }
    return -1;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int N,Q,i;
      long int x;
      S(N); S(Q);
      for(i=0;i<N;i++)
        scanf("%ld",&a[i]);
      while(Q--)
      {
         scanf("%ld",&x);
         P(bs(x,N));
      }
return 0;
}
