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
main()
{
          freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int N,i,j;
      S(N);
      int ga,da;
      pair<int,int>pa[N+2];
      for(i=0;i<N;i++)
      {
          S(ga); S(da);
          pa[i]= mp(ga,da);
      }
      sort(pa,pa+N);
      int visited[100005];
      LL milk=0;
      memset(visited,0,sizeof(visited));
      for(i=N-1;i>=0;i--)
      {
          ga= pa[i].first;
          da= pa[i].second;

          // try to milk just before da;
          for(j=da;j>=1;j--)
          {
              if(visited[j]==0)// unused slot
              {
                  visited[j]=1;
                  milk+= ga;
                 // P(ga);
                  break;
              }
          }
      }
      printf("%lld\n",milk);

return 0;
}
