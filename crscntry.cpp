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
LL mod=1000000007;
void multiply(LL F[2][2], LL M[2][2]);

void power(LL F[2][2], LL n);

/* function that returns nth Fibonacci number */
LL fib(LL n)
{
  LL F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0]%mod;
}

/* Optimized version of power() in method 4 */
void power(LL F[2][2], LL n)
{
  if( n == 0 || n == 1)
      return;
  LL M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(LL F[2][2], LL M[2][2])
{
  LL x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  LL y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  LL z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  LL w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
}


main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t;
      LL N,M,ans;
      S(t);
      // sum till nth fibo = fibo[n+2]-1
      while(t--)
      {
            SL(N); SL(M);
           // printf("%d %d\n",fib(N+1), fib(M+2));
            ans= (fib(M+2)- fib(N+1)+ mod)%mod;
            printf("%lld\n",ans);
      }
return 0;
}
