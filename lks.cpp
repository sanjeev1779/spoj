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
        int N,i,j;
        string str;
        S(N);
        cin>>str;
        int l= 2*N;
        int freq[6];
        memset(freq,0,sizeof(freq));
        for(i=0;i<l;i++)
        {
            if(str[i]=='A') freq[1]++;
            if(str[i]=='B') freq[2]++;
             if(str[i]=='C') freq[3]++;
             if(str[i]=='D') freq[4]++;

        }
        map<char,int>ma;
        map<int,char>ma1;
        ma['A']=1;  ma['B']=2;  ma['C']=3; ma['D']=4;
        ma1[1]='A';  ma1[2]='B';  ma1[3]='C'; ma1[4]='D';
        freq[1]= N- freq[1]; freq[2]= N- freq[2]; freq[3]= N- freq[3]; freq[4]= N- freq[4];
        string ans="";
        int flag=0;
        for(j=1;j<=4;j++)
        {
            if(j!=ma[str[0]] && j!= ma[str[1]])
            {
                ans+= ma1[j];
                freq[j]--;
            }
        }
       // cout<<ans<<endl;
        for(i=2;i<l;i++)
        {
                flag=0;
                for(j=1;j<=4;j++)
                {
                    if(j!= ma[ans[i-1]] && j!= ma[str[i]]  && j!= ma[str[i-1]])
                    {
                        freq[j]--;
                        ans+= ma1[j];
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    break;
        }
        if(flag==0)
        {
             memset(freq,0,sizeof(freq));
        for(i=0;i<l;i++)
        {
            if(str[i]=='A') freq[1]++;
            if(str[i]=='B') freq[2]++;
             if(str[i]=='C') freq[3]++;
             if(str[i]=='D') freq[4]++;

        }
         freq[1]= N- freq[1]; freq[2]= N- freq[2]; freq[3]= N- freq[3]; freq[4]= N- freq[4];
            flag=0;
            ans="";
                    for(j=4;j>=1;j--)
                    {
                        if(j!=ma[str[0]] && j!= ma[str[1]])
                        {
                            ans+= ma1[j];
                            freq[j]--;
                        }
                    }
               // cout<<ans<<endl;
                    for(i=2;i<l;i++)
                    {
                        // cout<<ans<<endl;
                        flag=0;
                        for(j=1;j<=4;j++)
                        {
                            if(j!= ma[ans[i-1]] && j!= ma[str[i]]  && j!= ma[str[i-1]])
                            {
                                freq[j]--;
                                ans+= ma1[j];
                                flag=1;
                             //   cout<<ans<<endl;
                                break;
                            }
                        }
                        if(flag==0)
                            break;
                    }
        }
        cout<<ans<<endl;
return 0;
}
