#include<iostream>
#include<stdio.h>
#include<math.h>
#define LL long long
#define SL(N) scanf("%lld",&N);
using namespace std;
LL p[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000};
LL M(LL X,LL C[],int D,int F)
{
    int i;
    int S = X/p[D];
    for(i=0;i<S;i++)
        C[i]+=p[D];
    C[S]+= X%p[D]+1;
    if(F)C[0]-= p[D];
     if(D==0) return 0;
        for(i=0;i<10;i++) C[i]+= S*D*p[D-1];
        if(F)
            C[0]-= (p[D]-1)/9;
        M(X%p[D],C,D-1,0);
}
main()
{
       LL a,b,i,x,C1[11],C2[11];
       int D;
       SL(a); SL(b);;
       while(a!=0 && b!=0)
       {
           memset(C1,0,sizeof(C1));
           memset(C2,0,sizeof(C2));
           if(a>b)swap(a,b);
           a--;
           if(a!=0){
               D= (int) floor(log10(a));
               M(a,C1,D,1);
           }
           D= (int) floor(log10(b));
           M(b,C2,D,1);
           for(i=0;i<10;i++)cout<<C2[i]-C1[i]<<" ";
           cout<<endl;
           SL(a); SL(b);
       }
return 0;
}
