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
#define N 550
using namespace std;

double dp[600][4000];

void Ini() {
    int i, j, k;
    memset(dp, 0, sizeof(dp));
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1.0/6.0;
    for(i = 2; i <= N; ++i) {
        for(j = i-1; j <= 6*(i-1); ++j)
            for(k = 1; k <= 6; ++k)
                dp[i][j+k] += dp[i-1][j]/6.0;
    }
}

int main() {
    Ini();
    //freopen("D.txt", "w", stdout);
    //for(int i = N; i <= 6*N; ++i) cout<<dp[N][i]<<endl;
    int Test;
    cin>>Test;
    while(Test--) {
        int n, num;
        cin>>n>>num;
        if(n > N || num < n || num > 6*n) {
            cout<<"0"<<endl;
            continue;
        }
        int ans = floor(100*dp[n][num]);
        cout<<ans<<endl;
    }
    return 0;
}
