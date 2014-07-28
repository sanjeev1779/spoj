#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N)
#define S(N) scanf("%d",&N)
#define SL(N) scanf("%lld",&N)
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    LL num;
    SL(num);
    if(num%10==0)
        P(2);
    else
    {
        P(1);
        P(num%10);
    }

return 0;
}
