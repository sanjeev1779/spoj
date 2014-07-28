#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,N,x,y;
      S(t);
      while(t--)
      {
          string str;
            S(N);
            int mapit[130];
            for(i=0;i<130;i++) mapit[i]=-1;

            char ch1,ch2,temp;
           // map<char,char>ma;
            while(N--)
            {
                cin>>ch1>>ch2;
                 x= ch1;
                 y= ch2;
                mapit[x]=y;
            }
            cin>>str;
            int l =str.size();
            for(i=0;i<l;i++)
            {
                temp= str[i];
                if(mapit[temp]!=-1)
                {
                    str[i]= mapit[temp];
                }
            }
            int lt=0;
            for(i=0;i<l;i++)
            {
                if(str[i]=='0')
                    lt++;
                else break;
            }

            int rt=l-1;
            for(i=l-1;i>=0;i--)
            {
                if(str[i]=='0')
                    rt--;
                else break;
            }

            if(lt==rt)// both 0
            {
                cout<<"0\n"; continue;
            }
            if(str[lt]!='.' && str[rt]=='.') // lt non zero and rt zero
            {
                for(i=lt;i<rt;i++)
                    cout<<str[i];
                cout<<endl;
                continue;
            }
            else
            {
                for(i=lt;i<=rt;i++)
                {
                    cout<<str[i];
                }
                cout<<endl;
                continue;
            }
      }
return 0;
}
