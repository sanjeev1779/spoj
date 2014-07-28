#include <bits/stdc++.h>
using namespace std;


long long cal(long long x, long long y)
{
    long long temp;
    while(y>0)
    {
        temp= x%y;
        x=y;
        y= temp;
    }
    return x;
}
int dp(string str)
{
    int len= str.length();
    int digitjump[len+2];
    int digit[12];
    //memset(digitjump,len+5,sizeof(digitjump));
    //memset(digit,len+5,sizeof(digit));
    for(int i=0;i<=len;i++) digitjump[i]= len+100;
    for(int i=0;i<10;i++)digit[i]=len+100;
    // base cases
    digitjump[0]=0;
    digit[str[0]-'0']=0;
    for(int i=1;i<len;i++)
    {
        digitjump[i]= min(digitjump[i-1], digit[str[i]-'0'])+1;
        digit[str[i]-'0']= min(digitjump[i],digit[str[i]-'0']);
    }
    for(int i=len-2;i>=0;i--)
    {
        digitjump[i]= min(digitjump[i],min(digitjump[i+1], digit[str[i]-'0'])+1);
        digit[str[i]-'0']= min(digitjump[i],digit[str[i]-'0']);
    }

    digit[str[0]-'0']=0;
    for(int i=1;i<=len-2;i++)
    {
        digitjump[i]= min(digitjump[i-1],min(digitjump[i+1], digit[str[i]-'0']))+1;
        digit[str[i]-'0']= min(digit[str[i]-'0'],digitjump[i]);
    }

    if(len>=2)// single length , ans=0
        digitjump[len-1]= min(digitjump[len-2], digit[str[len-1]-'0'])+1;


    return digitjump[len-1];
}
int main()
{
        string str;
        cin>>str;
        cout<<dp(str)<<endl;
    return 0;
}
