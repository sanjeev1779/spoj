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
LL BIT[10005];
int N;
void update(int idx, int val)
{
    while(idx<=N)
    {
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}
LL getsum(int idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
       //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
       int t,u,val,l,r,q,idx;
       S(t);
       LL left,right,ans;
       while(t--)
       {
           memset(BIT,0,sizeof(BIT));
            S(N);S(u);
            while(u--)
            {
                scanf("%d %d %d",&l,&r,&u);l++;r++;
                update(l,val);
                update(r+1,-val);
            }
            S(q);
            while(q--)
            {
                S(idx);
                printf("%lld\n",getsum(idx));
            }

       }
return 0;
}
