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
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int t,l,r,len,flag,left,right;
    S(t);
    string str;
    while(t--)
    {
        cin>>str;
        len = str.size();
        left=0;
        right=len-1;
        l=1;r=1;
        flag=0;
        while(left<right)
        {
            if(str[left]==str[right])
            {
                left++; right--;
            }
            else
            {
                if(left>=1 && str[left]==str[left-1]) left++;
                else if(right+1 <l && str[right]==str[right+1]) right--;
                else { flag=1; break;}
            }
//            if(str[left]==str[left+1])l++; else l=1;
//            if(str[right]==str[right-1]) r++; else r=1;
        }
        if(flag==0) printf("YES\n");
        else printf("NO\n");
    }
return 0;
}
