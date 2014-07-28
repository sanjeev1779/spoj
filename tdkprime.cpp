#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;
#define pb push_back
int Prime[1100000];
vector<int>pos; // holds the prime number at ith index
#define prime(i) ((Prime[i>>5])&(1<<(i&(31))))
#define set(j) (Prime[j>>5]|=(1<<(j&(31))))
#define LIM 100000002
#define SLIM 10001
void sieve()
{
        int i, j, m, n, t,x,k,l,h;
        set(1);
        pos.pb(0);
        pos.pb(2);
        pos.pb(3);
        for(k=2,l=3,i=5; i<=SLIM; k++,i=3*k-(k&1)-1)
                if(prime(k)==0)
                {
                        pos.pb(i);
                        for(j=i*i,h=((j+2)/3); j<=LIM; h+=(k&1)?(h&1?((k<<2)-3):((k<<1)-1)):(h&1?((k<<1)-1):((k<<2)-1)),j=3*h-(h&1)-1)
                        set(h);
                }

        i=3*k-(k&1)-1;
        for(; i<=LIM; k++,i=3*k-(k&1)-1)
            if(prime(k)==0)
                pos.pb(i);
        return;
}
int main()
{
    int x,idx,pi;
    sieve();
    int i=1;
    cout<<pos[100]<<endl;
    int l= pos.size();
    while(i<l)
    {
       // printf("%d\n",pos[i]);
        i+=100;
    }
    return 0;
}
