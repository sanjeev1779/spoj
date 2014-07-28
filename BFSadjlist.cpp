
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

// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
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
     // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    cnt--;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty()&&cnt>0)
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end()&&cnt>0; ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                cnt--;
                queue.push_back(*i);
            }
        }
    }

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
         freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);

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

    g.BFS(0);


    return 0;
}



