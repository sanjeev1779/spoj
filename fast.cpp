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
int gcd(int a,int b)
{
        while (b > 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
}
main()
{
        freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int t,b,m1,n1;
    S(t);
    int x1,x2,x3,x4,y1,y2,y3,y4,area;
    double ans;
    while(t--)
    {
        cin>>x1>>y1;
        cin>>x2>>y2;
        m1= abs(x2-x1), n1= abs(y2-y1);
        b= m1+n1- gcd(m1,n1);
        cin>>x3>>y3;

         m1= abs(x3-x2), n1= abs(y3-y2);
         b+= m1+n1- gcd(m1,n1);
        cin>>x4>>y4;

        m1= abs(x4-x3), n1= abs(y3-y4);
         b+= m1+n1- gcd(m1,n1);

        m1= abs(x1-x4), n1= abs(y1-y4);
         b+= m1+n1- gcd(m1,n1);

        b=b-4;
        cout<<b<<endl;
        area= abs(x1*y2-y1*x2 + x2*y3-x3*y2 + x3*y4-x4*y3 + x4*y1-x1*y4);
        ans= area*1.0/2.0;
        cout<<ans<<endl;
    }

return 0;
}
