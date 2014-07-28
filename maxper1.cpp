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
LL mod= 1000000007;
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
inline void writeInt(LL x)
{
     if(x==-1)
     {
              PUTCHAR('-');
              PUTCHAR('1');
              PUTCHAR('\n');
     }
     else
     {
       int i = 10;
       char buf[11];
      // buf[10] = 0;
      buf[10] = ' ';

     do
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != ' ');
     }
}


inline void fl(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-') {
            neg = 1;
        c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}

LL fastpow(LL a, int b)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2) prod= (prod*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return prod;
}
main()
{
        // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,cd,prev,N,cur;
      S(t);

      LL dp[105][204]; // dp[i][j] = # of subsequence ending with i having cd = j
      int freq[105];
      while(t--)
      {
            fl(N);
            memset(freq,0,sizeof(freq));
            memset(dp,0,sizeof(dp));
            for(i=1;i<=N;i++)
            {
                fl(cur); // current element
                for(j=0;j<=200;j++)
                {
                    cd=j-100; // common diff is scaled up by 100,
                    prev= (cur-cd);
                    if(prev<1 || prev>100) continue; // out of range

                    if(cd==0)
                    {
                        dp[cur][j] = (2*dp[cur][j]+1)%mod;
                    }
                    else
                    {
                        dp[cur][j]= ( dp[cur][j]+ (dp[prev][j]+freq[prev]))%mod;
                    }
                }
                freq[cur]++;
            }
            LL AP=0;
            for(i=0;i<=100;i++)
            {
                for(j=0;j<=200;j++)
                    AP= (AP+dp[i][j])%mod;
            }
          //  printf("%lld\n",AP);
           LL subsets= fastpow(2,N);
           LL nonAPs= (subsets-AP-1+mod)%mod; // total subsets - AP - nullset
           writeInt(nonAPs);
      }
return 0;
}

