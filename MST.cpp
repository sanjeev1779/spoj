
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
#define p pair<int, int>
using namespace std;
int id[10004];
int find(int i)
{
	while(i!=id[i])
	{
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int n,m,x,y,z,i;
      S(n);
      S(m);
      pair<int,p>cost[m+2];
      for(i=0;i<m;i++)
      {
          S(x);S(y);S(z);
          cost[i]=mp(z,mp(y,x));
      }
        sort(cost,cost+m);
        map<int,int>hashmap;
        int edge=0;
        LL sumcost=0;
        for(i=0;i<=n;i++)id[i]=i;
        for(i=0;i<m;i++)
        {
            x=cost[i].second.first;y=cost[i].second.second;
            z=cost[i].first;
            int f1=find(x);
            int f2=find(y);
            if(f1!=f2)
            {
                id[f1]=f2;
                sumcost+=z;
            }

        }
        cout<<sumcost;


return 0;
}
