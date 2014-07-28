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
int check(vector<int>vec)
{
    int l= vec.size();
    if(l<=2) return l;

    int cd= vec[1]-vec[0];
    for(int i=2;i<l;i++)
    {
        if(vec[i]-vec[i-1]!=cd)
            return 0;
    }
    return 1;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t;
      S(t);
      int a[100],n;
      while(t--)
      {
            S(n);
            for(i=0;i<n;i++)
            {
                cin>>a[i];
            }
            int subsets= 1<<n;
          //  P(subsets)
            int cnt=0;
            for(i=0;i<subsets;i++)
            {
                vector<int>vec;
                for(j=0;j<n;j++)
                {
                    if(i& (1<<j))
                    {
                        vec.pb(a[j]);
                    }
                }
                if(vec.size()>0)
                {
                    if(check(vec))
                        cnt++;
                    else
                    {
                        for(int k=0;k<vec.size();k++)printf("%d ",vec[k]);
                        printf("\n");
                    }
                }
            }
            P(cnt);// # of APs
            P(subsets-cnt-1); // # of non APs
      }
return 0;
}
