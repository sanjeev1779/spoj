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
int chain[1003][1003];
int lcs[1003][1003];
main()
{
//freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int l;
      string a,b;
      cin>>l;
      while(l!=0)
      {
            cin>>a>>b;
            memset(chain,0,sizeof(chain));
            memset(lcs,0,sizeof(lcs));
            int n=a.length();
            int m=b.length();
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                    if(a[i-1]==b[j-1])
                    {
                        chain[i][j]=chain[i-1][j-1]+1;
                        if(chain[i][j]>=l)
                        {
                            for(int k=l;k<=chain[i][j];k++)
                            {
                                lcs[i][j]=max(lcs[i][j],lcs[i-k][j-k]+k);
                            }
                        }
                    }
                }
            }

            cout<<lcs[n][m]<<endl;
            cin>>l;
      }




      return 0;

}
