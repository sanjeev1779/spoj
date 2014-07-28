#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=b-1;i>=a;i--)
using namespace std;
typedef long long LL;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
    int t, n, m, c, p;
    int k;  //number of different colors
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int colors[42] = {0};    //number of balloons with color=i
        int cost[42] = {0};      //sum of costs of all balloons with color=i
        k = 0;
        bool ispresent[42] = {0};
        loop(i, 0, n)
        {
            cin>>c>>p;
            ispresent[c] = true;
            colors[c]++;
            cost[c] += p;
        }
        loop(i, 1, 41) if(ispresent[i]) k++;

        LL dp1[42][42] = {{0}};
        //number of subsets containing colors 1 to i, having j distinct colors
        //the denominator
        loop(i, 0, 41) dp1[0][i] = 0;
        loop(i, 0, 41) dp1[i][0] = 1;
        loop(i, 1, 41)
        {
            loop(j, 1, 41)
                dp1[i][j]= dp1[i-1][j] + dp1[i-1][j-1]*((1<<colors[i])-1);
                // we are not using the i'th color +
                // we use the i'th color
                // now, we can choose any combination of colors[i] balloons.
                // but not the one in which no balloon is present.
                // therefore, we have (2**colors[i])-1 different ways.
        }

        LL dp2[42][42] = {{0}};
        //the total cost of all subsets having colors 1 to i, and j distinct colors.
        //the numerator
        loop(i, 1, 41)
        {
            loop(j, 1, i+1)
                {
                    dp2[i][j] = dp2[i-1][j] + dp2[i-1][j-1]*((1<<colors[i])-1) + dp1[i-1][j-1]*cost[i]*(1<<(colors[i]-1));
                    if(ispresent[i])cout<<dp2[i][j]<<" ";
                }
           if(ispresent[i]) cout<<endl;
                // we are not using the i'th color #1
                // we use the i'th color
                // we again have (2**colors[i])-1 options
                // so we add #2
                // also, we add #3
                // total sum for selecting i'th color * number of ways of selecting j-1 colors from i-1 colors(DP1[i-1][j-1])
                // total sum for selecting i'th color is cost[i]*(2**(colors[i]-1)). How?
        }
        LL num = 0, den = 0;
        loop(i, m, 41)
        {
            num += dp2[40][i];
            den += dp1[40][i];
        }
        cout<<num<<" "<<den<<endl;
        cout <<fixed<<setprecision(6)<<double(num)/double(den)<<endl;
    }
	return 0;
}
