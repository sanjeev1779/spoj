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
int lcs(string str1, int l)
{
    int ans=0,i,j,temp=0;
    int LCSuff[2][l+1];
    int tmp=1;
    for(i=0;i<=l;i++) { LCSuff[0][i]= LCSuff[1][i]=0;}
    for (int i=1; i<=l; i++)
    {
        for (int j=1; j<=l; j++)
        {
            if (str1[i-1] == str1[l-j])
            {
                LCSuff[tmp][j] = LCSuff[!tmp][j-1] + 1;
            }
            else {LCSuff[tmp][j]= max(LCSuff[!tmp][j],LCSuff[tmp][j-1]);}
        }
        tmp=!tmp;
    }
    return LCSuff[!tmp][l];
}
int main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int t,i,l,j,ans,lcs_len;
    t=1;

    while(t--)
    {
        string str1,str2;
       S(l);
        cin>>str1;
        lcs_len= lcs(str1,l);
       // cout<<lcs_len<<endl;
        ans=l -lcs_len;
        P(ans);
    }
return 0;
}
