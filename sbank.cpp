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
#define traverse_map(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
main()
{
          freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int i,n,test,freq;
    S(test);
    while(test--){
    S(n);
    string num;
    char str[18];
    map<string,int>m;
    cout<<"hi\n";
    while(n--)
        {
            gets(str);
            getchar();
            cout<<"hi\n"<<endl;
           // m[str]++;
        }
        traverse_map(m,i)
        {
            num= (*i).first;
            freq= (*i).second;
            cout<<num<<" "<<freq<<endl;
        }
        cout<<endl;
    }
return 0;
}
