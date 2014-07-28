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
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int N,M,i,x,y,flag;
      cin>>N>>M;
      int freq[N+2];
      memset(freq,0,sizeof(freq));
      for(i=0;i<M;i++)
      {
          cin>>x>>y;
          freq[y]++;
      }

      if(N!=M+1)
         printf("NO\n");
      else printf("YES\n");
return 0;
}
