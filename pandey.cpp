#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>

#define ll long long

using namespace std;



int n;

void update_sum(ll idx,ll val,ll mod,ll *L)
{
    for(ll i=idx;i<n;i++)
        L[i]=((L[i]%mod)+(val%mod))%mod;
}

void update_mul(ll idx,ll val,ll mod,ll *L)
{
    for(ll i=idx;i<n;i++)
        L[i]=((L[i]%mod)*(val%mod))%mod;
}




int main()
{
    ll t,i,a,b,c;
    scanf("%lld",&t);
   string s;
    while(t--)
    {
        scanf("%d",&n);
        ll L[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&L[i]);
        }

        scanf("%lld %lld %lld",&a,&b,&c);
        cin>>s;
        char ch;
        for(i=0;i<s.size();i++)
        {
            ch=s[i];
            switch(ch)
            {
            case 'A':
                update_sum(i,a,c,L);
                break;
            case 'M':
                update_mul(i,b,c,L);
                break;
            case 'R':
                reverse(L+i,L+n);
                break;
            }
            printf("%lld ",L[i]%c);
        }
        printf("\n");


    }
}
