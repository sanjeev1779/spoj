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

      int x,i,N,j;
      S(N);
      vector<int>vec;
      for(i=0;i<N;i++)
      {
          S(x); vec.pb(x);
      }
        int cnt=0;
      while(vec.size()>0)
      {
          for(i=0;i<vec.size();i++)
          {
                for(j=0;j<vec.size();j++)
                {
                    if(vec[j]>=vec[i])
                        vec.erase(vec.begin()+j);
                }
                cnt++;
          }
      }
      cout<<cnt<<endl;

return 0;
}
