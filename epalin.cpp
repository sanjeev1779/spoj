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

string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n+5];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

    int s_len= s.size();
  // Find the maximum element in P.
  int maxLen = 0,x;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {

   x= (i-1-P[i])/2 + P[i];
  //cout<<i<<" :: "<<x<<" :: "<<P[i]<<endl;
    if (x==s_len &&  P[i]> maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
    int start_index= (centerIndex - 1 - maxLen)/2;
    string ans= s;
    //cout<<start_index<<endl;
    for(int i=start_index-1;i>=0;i--)
        ans+= s[i];
    //delete[] P;
 // return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
   return ans;
}
main()
{
        // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);

    while(!cin.eof())
    {
        string str;
        cin>>str;
        string palin= longestPalindrome(str);
        cout<<palin<<endl;
    }
return 0;
}

