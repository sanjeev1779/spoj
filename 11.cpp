// codeforces
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
bool cmp(int a,int b) { if(a>b) return true; return false;}
struct _ {
    ios_base::Init i;

    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
    }
} _;
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int i,l,flag,vl;
    string str1,str2;
       while(1)
       {
           string str;
           cin>>str;
           if(str=="*") break;
           l= str.length();
           vector<int>vec;
           for(i=1;i*i<=l;i++)
           {
                if(l%i==0)
                {
                    vec.pb(i);
                    if(i*i!=l)
                       {
                            vec.pb(l/i);
                       }
                }
           }
            sort(vec.begin(),vec.end());
            vl= vec.size();
          // for(i=0;i<vec.size();i++) printf("%d ",vec[i]);
          // printf("\n");

          for(i=0;i<vl;i++)
          {
              flag=0;
              str1= str.substr(0,vec[i]);
              for(int j=vec[i];j<l;j+=vec[i])
              {
                   str2= str.substr(j,vec[i]);
                   if(str1!=str2) {  flag=1;break;}
              }
              if(flag==0)
              {
                  P(l/vec[i]);
                  break;
              }
          }
       }
return 0;
}
