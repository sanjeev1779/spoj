#include <cstdio>
#include <algorithm>
#include <cstring>
#include<iostream>
using namespace std;

#define MAXN 65536
#define MAXLG 17

char A[MAXN];

struct entry
{
    int nr[2];
    int p;
} L[MAXN];

int sortIndex[MAXLG][MAXN];
int N,i;
int stp, cnt;

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int main()
{
    gets(A);
    int j;
    N=strlen(A);
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
    for(i=0;i<stp;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<sortIndex[i][j]<<"  ";
        }
        cout<<"\n";
    }
    return 0;
}
