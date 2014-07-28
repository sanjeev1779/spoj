#include<cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

#define LL long long
#define MAXN 65536
#define MAXLG 17

struct elem{
    int ind,ran;
};
struct entry
{
    int nr[2];
    int p;
} L[MAXN];

int sortIndex[MAXLG][MAXN];
int N,i;
int stp, cnt;

int lcp(int x, int y)
{
    int k, ret = 0;
    if (x == y) return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --)
    if (sortIndex[k][x] == sortIndex[k][y])
    x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int compare(elem e1, elem e2)
{
        return (e1.ran<e2.ran);
}

int main()
{
    int test,x;
    cin>>test;
    LL l;
    char A[50005];
    while(test--){
        scanf("%s",A);
        getchar();
        int j;
        N=strlen(A);
      //  cout<<N<<endl;
        l=N;
        for( i = 0; i < N; i++)
            sortIndex[0][i] = A[i] - 'a';

        for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
        {
            for(i=0; i < N; i++)
            {
                L[i].nr[0]=sortIndex[stp- 1][i];
                L[i].nr[1]=i +cnt <N ? sortIndex[stp -1][i+ cnt]:-1;
                L[i].p= i;
            }

            sort(L, L+N, cmp);
            for(i=0; i < N; i++)
                sortIndex[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? sortIndex[stp][L[i-1].p] : i;
        }
        elem str[N];
       for(i=0;i<N;i++)
       {
            str[i].ran= sortIndex[stp-1][i];
            str[i].ind=i;
       }
     //  sort(str.begin(),str.end(),compare);
     qsort(str,N,sizeof(elem),compare);
       LL ans=l*(l+1)/2;
       LL lcpsum=0;
       for(i=1;i<l;i++)
       {
           x=lcp(str[i-1].ind, str[i].ind);
          // cout<<"x = "<<x<<endl;
            lcpsum+=x;
       }
       ans-=lcpsum;
       printf("%lld\n",ans);
    }
    return 0;
}
