#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
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
main()
{
    stack<char>op;
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                cout<<str[i];
            else
                if(str[i]=='(')
                   op.push(str[i]);
            else
                if(str[i]==')')
            {
                cout<<op.top();
                op.pop();op.pop();
            }
            else
                 op.push(str[i]);

        }
    }
return 0;
}
