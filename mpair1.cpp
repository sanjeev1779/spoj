#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<climits>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
#define traverse_map(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;

#define maxn 1000001
int id[maxn],siz[maxn];
int root(int i)
{
	while(i!=id[i])
	{
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}
bool connected(int p,int q)
{
	return root(p) == root(q);
}
void Union(int p,int q)
{
	int i = root(p);
	int j = root(q);
	if(i==j)
		return;
	if(siz[i] < siz[j])
	{
		id[i] = j;
		siz[j] += siz[i];
	}
	else
	{
		id[j] = i;
		siz[i] += siz[j];
	}
}
int main()
{
	int i,j,t,it;
    //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
	LL n;
	cin >> n;
	int m;
	S(m);
	for(i=1;i<=n;i++)
	{
		id[i] = i;
		siz[i] = 1;
	}
	int x,y,x1,y1;
	while(m--)
	{
		S(x);
		S(y);
		Union(x,y);
	}
	map<int,int>map_it;
	for(i=1;i<=n;i++)
    {
        map_it[id[i]]++;
    }
    LL ans=0;
    traverse_map(map_it,it)
    {
        x= (*it).second;
        x1= (*it).first;
        traverse_map(map_it,it1)
        {
            y1= (*it1).first;
            if(x1!=y1)
               {
                y= (*it1).second;
                ans+=(LL)y*x;
               }
        }
    }
    cout<<ans/2<<endl;
	return 0;
}
