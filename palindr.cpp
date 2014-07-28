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
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

string manacher(string str)
{
    string T= preProcess(str);
    int len_T= T.size();
    int P[len_T+2];
    int i_mir,R=0,C=0;
    for(int i=1;i<len_T-1;i++)
    {
        i_mir= 2*C-i;
        P[i]=(R>i)? min(R-i,P[i_mir]):0;

        while(T[i+1+P[i]]==T[i-1-P[i]])P[i]++;

        if(i+P[i]>R)
        {
            C=i;
            R=i+P[i];
        }
    }
    //cout<<"hi\n";
   // for(int i=1;i<len_T-1;i++) cout<<P[i]<<" ";
    //cout<<endl;
    int ended=-1,start;
    for(int i=1;i<len_T-1;i++)
    {
        start=(i-1-P[i])/2;
     //  cout<<"start= "<<P[i]<<" ="<<start<<endl;
        if(P[i]%2==0 && P[i]>0)
        {
           // cout<<"found start= "<<start<<endl;
           if( (start-1)==ended)
           {
               ended=start+P[i]-1;
              //cout<<"ended= "<<ended<<endl;

           }
        }
    }
    if(ended==str.size()-1)
        return "YES";
    return "NO";
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int t;
      S(t);
      while(t--)
      {
          string str;
          cin>>str;
          if(str.size()%2==1)cout<<"NO\n";
          else cout<<manacher(str)<<endl;
      }
return 0;
}
