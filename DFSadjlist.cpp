#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<list>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%ld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int a[502][502];
int n,m,k;
int cnt;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cnt--;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end()&&cnt>0; ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{

    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==-1)
                printf("#");
            else{
                    if(visited[a[i][j]])
                        printf(".");
            else
                printf("X");

            }
        }
        printf("\n");
    }
}

int main()
{
    int i,j;
    cin>>n>>m>>k;
    char str[502];
    int node=0;
    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        for(j=1;j<=m;j++)
        {
            if(str[j-1]=='#')
                a[i][j]=-1;
            else {
                a[i][j]=node;
                node++;
            }
        }
    }
    cnt=node-k;

    Graph g(node+1);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]>=0)
            {
                if(a[i+1][j]>=0)
                {
                    g.addEdge(a[i][j],a[i+1][j]);
                }
                if(a[i][j+1]>=0)
                {
                    g.addEdge(a[i][j],a[i][j+1]);
                }
            }
        }
    }

    g.DFS(0);


    return 0;
}



