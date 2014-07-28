#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;

int getMid(int s, int e) {  return s + (e -s)/2;  }
LL RMQUtil(LL *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
       {
            return st[index];
       }
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return min(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
LL RMQ(LL *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
LL constructSTUtil(LL arr[], int ss, int se, LL *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  min(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
LL *constructST(LL arr[], int n)
{
    int x = (ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    LL *st = new LL[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int a[50005];
    int N;
     cin>>N;
     int i,M,x,y,maxm;
     for(i=0;i<N;i++)
     {
         cin>>a[i];
         a[i]= -a[i];
     }
     cin>>M;
     int *st= constructST(a,N);
     while(M--)
     {
         cin>>x>>y;
         maxm= -RMQ(st,N,x-1,y-1);
        cout<<maxm<<endl;
     }
return 0;
}
