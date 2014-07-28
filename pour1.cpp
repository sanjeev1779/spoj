#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<queue>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int bfs(int a, int b, int c)
{
    queue<pii>qu;
    pair<int,int>pat;
    pair<int,int>p1;
    //map<pair<int,int>,int>ma;
    pat=mp(0,0);
    qu.push(pat);
    int a1_copy,b1_copy,a1,b1,to_por;
    map<pii,int>dist;
    dist[pat]=0;
    while(!qu.empty())
    {

        //6 cases
        p1= qu.front();
        qu.pop();
        a1= p1.first; b1= p1.second;
       // printf("state = %d %d\n",a1,b1);
        if(a1==c || b1==c)
        {
            return dist[p1];
        }
        a1_copy=a1, b1_copy=b1;
        if(a1>0) // empty first
        {
            a1_copy=0; b1_copy=b1;
            pat= mp(a1_copy,b1_copy);
            if(dist.find(pat)==dist.end())// not present
            {
                qu.push(pat);
                dist[pat]= dist[p1]+1;
             //   printf("entered 1: %d %d\n",a1_copy,b1_copy);
            }
        }
        if(b1>0)
        {
            a1_copy=a1; b1_copy=0;
            pat= mp(a1_copy,b1_copy);
            if(dist.find(pat)==dist.end())// not present
            {
                qu.push(pat);
                dist[pat]= dist[p1]+1;
               // printf("entered 2: %d %d\n",a1_copy,b1_copy);
            }
        }
        if(a1<a) // full it
        {
            a1_copy=a; b1_copy=b1;
            pat= mp(a1_copy,b1_copy);
           if(dist.find(pat)==dist.end())// not present
            {
                qu.push(pat);
                dist[pat]= dist[p1]+1;
               // printf("entered 3: %d %d\n",a1_copy,b1_copy);
            }
        }

        if(b1<b)
        {
            a1_copy=a1; b1_copy=b;
            pat= mp(a1_copy,b1_copy);
           if(dist.find(pat)==dist.end())// not present
            {
                qu.push(pat);
                dist[pat]= dist[p1]+1;
               // printf("entered 4 b fulled: %d %d\n",a1_copy,b1_copy);
            }
        }
        // 5th possibility
        // pouring a into b
        if(b1<b) // then pouring is possible, pour a to b
        {
            a1_copy=a1; b1_copy=b1;
            to_por= b-b1;
            if(a1_copy>to_por)
            {
                 a1_copy-=(to_por);
                 b1_copy=b;
            }
            else
            {
                a1_copy=0;
                b1_copy+=a1;
            }
            pat= mp(a1_copy,b1_copy);
            if(dist.find(pat)==dist.end())// not present
            {
                qu.push(pat);
                dist[pat]= dist[p1]+1;
               // printf("entered 5 : %d %d\n",a1_copy,b1_copy);
            }
        }
        if(a1<a) // last condition , pour from b to a
        {
             a1_copy=a1; b1_copy=b1;
             to_por= a-a1;
             if(b1_copy>to_por)
             {
                 b1_copy-=(to_por);
                 a1_copy=a;
             }
             else
             {
                 b1_copy=0;
                 a1_copy+=b1;
             }
              pat= mp(a1_copy,b1_copy);
           if(dist.find(pat)==dist.end())// not present
            {
                qu.push(pat);
                dist[pat]= dist[p1]+1;
               // printf("entered 6: %d %d\n",a1_copy,b1_copy);
            }
        }
        // all conditions end
    }// while queue loop end
    return -1;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int a,b,c,t,x;
      S(t);
      while(t--)
      {
            scanf("%d %d %d",&a,&b,&c);
            x=bfs(a,b,c);
            P(x);
      }
return 0;
}
