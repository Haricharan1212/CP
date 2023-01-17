// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

int modexp(long long x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

vector<bool> sieve(int n)
{
    // Time Complexity:- O(log(log(n)))

    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && 1LL * i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return is_prime;
}

// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph
{
    // No. of vertices
    int V;

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // A function used by DFS
    void DFSUtil(int v, bool visited[]);

public:
    // Constructor
    Graph(int V);

    void addEdge(int v, int w);
    int NumberOfconnectedComponents();
};

// Function to return the number of
// connected components in an undirected graph
int Graph::NumberOfconnectedComponents()
{

    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // To store the number of connected components
    int count = 0;
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            DFSUtil(v, visited);
            count += 1;
        }
    }

    return count;
}

void Graph::DFSUtil(int v, bool visited[])
{

    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// Add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vii a(n + 2, vector<int>(m + 2, 0));
    int count = 0;
    rep(i, 1, n + 1)
    {
        string s;
        cin >> s;
        rep(j, 1, m + 1)
        {
            a[i][j] = (s[j - 1] == '.' ? 1 : 0);
        }
    }

    rep(i, 0, n + 2) rep(j, 0, m + 2) if (!a[i][j]) count++;

    Graph g((n + 2) * (m + 2));

    rep(i, 1, n + 1) rep(j, 1, m + 1)
    {
        if (a[i][j])
        {
            if (a[i][j - 1])
                g.addEdge(i * m + j, i * m + (j - 1));
            if (a[i][j + 1])
                g.addEdge(i * m + j, i * m + (j + 1));
            if (a[i - 1][j])
                g.addEdge((i - 1) * m + j, i * m + j);
            if (a[i + 1][j])
                g.addEdge((i + 1) * m + j, i * m + j);
        }
    }
    cout << g.NumberOfconnectedComponents() - count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
