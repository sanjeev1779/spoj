#include<iostream>
#include<stdio.h>
#define S(n) scanf("%d",&n);
using namespace std;
main()
{

        int n,m,i,j;
        S(n) S(m)
        int ar[n+5];
        int br[m+5][3];
        for(i=1;i<=n;i++)
             cin>>ar[i];
        for(j=1;j<=m;j++)
        {
            cin>>br[i][0]>>br[i][1];
        }
        for(i=1;i<=n;i++)
        {
            if(ar[i]%2)
                cout<<"0 ";
            else cout<<"1 ";
        }
        printf("\n");
return 0;
}
