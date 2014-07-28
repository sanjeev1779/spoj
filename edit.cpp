
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
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int check(string str)
{
    int i,l=str.size(),cnt=0;
    int left=0,right=l-1;
    while(left<right)
    {
        if(str[left]==str[right])
        {
            left++; right--;
        }
        else cnt++;
    }
    if(cnt==1 || cnt==0 && l%2==1)
        return 1;
    return 0;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,l,cnt,flag;
      string str1,str2,str;
      cin>>str;
      while(str!="*END*")
      {
          flag=0;
          l= str.size();
          cout<<str<<endl;
          str1="";
          for(i=0;i<l;i++)
          {
              str1+=str[i];
              str2= str.substr(i+1,l-i-1);
              if(check(str1)==1 && check(str2)==1)
              {
                  flag=1; break;
              }
          }
          if(flag)
          {
             cout<<str<<" is a double near palindrome.\n";
          }
          else
          {
            cout<<str<<" is not a double near palindrome.\n";
          }
          //another test case
          cin>>str;
      }
return 0;
}
