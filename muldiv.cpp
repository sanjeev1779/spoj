
#include <bits/stdc++.h>
using namespace std;

struct _ {
    ios_base::Init i;

    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
    }
} _;


main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,n,x,x1,y1,ans;
      cin>>n;
      string str;
      string ls[]={"00","00","00","00","01","01","01","01","10","10","10","10","11","11","11","11"};
      string rs[]={"00","01","10","11","00","01","10","11","00","01","10","11","00","01","10","11"};
        cin>>str;
         string left="",right="";
         int ca=0;
         for(i=n;i>=0;i)
         {
             x= str[i]-'0';
             if(x<10)
             {
                int l1= ls[x].substr(1,1)-"0";
                int r1= rs[x].substr(1,1);
                int l0= rs[x].substr(0,1);
                int r0= rs[x].substr(0,1);

                x1= l1; y1= r1-'0';
                ans=x1+y1+ca;
                val= ans%2; ca=ans/2;
                printf("%d",val);
                 x1= l0-'0'; y1= r0-'0';
                ans=x1+y1+ca;
                val= ans%2; ca=ans/2;
                printf("%d",val);

             }
             else
             {
                 x= str[i]-'A'+10;
                 int l1= ls[x].substr(1,1);
                int r1= rs[x].substr(1,1);
                int l0= rs[x].substr(0,1);
                int r0= rs[x].substr(0,1);

                x1= l1-'0'; y1= r1-'0';
                ans=x1+y1+ca;
                val= ans%2; ca=ans/2;
                printf("%d",val);
                 x1= l0-'0'; y1= r0-'0';
                ans=x1+y1+ca;
                val= ans%2; ca=ans/2;
                printf("%d",val);
             }
             //cout<<left<<" and "<<right<<endl;
         }

return 0;
}
