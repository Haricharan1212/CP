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

const int N = 100000;

// variables to be used
// in both functions
vector<int> graph[N];
vector<vector<int>> cycles;

// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int &cyclenumber)
{

    // already (completely) visited vertex.
    if (color[u] == 2)
    {
        return;
    }

    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1)
    {
        vector<int> v;
        cyclenumber++;

        int cur = p;
        v.push_back(cur);

        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u)
        {
            cur = par[cur];
            v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[u] = p;

    // partially visited.
    color[u] = 1;

    // simple dfs on graph
    for (int v : graph[u])
    {

        // if it has not been visited previously
        if (v == par[u])
        {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }

    // completely visited.
    color[u] = 2;
}

// add the edges to the graph
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Function to print the cycles
void printCycles(int &cyclenumber)
{

    // print all the vertex with same cycle
    for (int i = 0; i < cyclenumber; i++)
    {
        // Print the i-th cycle
        cout << "Cycle Number " << i + 1 << ": ";
        for (int x : cycles[i])
            cout << x << " ";
        cout << endl;
    }
}

void dfs(int node, vii &adj, vi &visited)
{
    visited[node] = true;
    for (int child : adj[node])
    {
        if (visited[child] == false)
            dfs(child, adj, visited);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vii adj(n);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool<visited>(n, false);

    rep(i, 0, n)
    {

        if (visited[i] == false)
            dfs(i, adj, visited);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
