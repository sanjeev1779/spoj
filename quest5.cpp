#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%ld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int t,i,n,l1,l2,g;
      string str1,str2,str3,str4;
      S(t);
      while(t--)
      {
            cin>>str1>>str2;
            l1=str1.size();
            l2=str2.size();
            g= gcd(l1,l2);
            str3= str1.substr(0,g);
            int cnt=0;
            for(i=0;i<l1;i+=g)
            {
                str4= str1.substr(i,g);
                if(str4==str3)
                {
                    cnt++;
                }
            }
            //cout<<str3<<endl;
            int cnt1=0;
            for(i=0;i<l2;i+=g)
            {
                str4= str2.substr(i,g);
                if(str4==str3)
                {
                    cnt1++;
                }
            }
            if(cnt==l1/g && cnt1==l2/g) printf("YES\n");
            else printf("NO\n");
      }
return 0;
}
