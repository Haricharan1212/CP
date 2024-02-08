// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)

int get_k(vii &arr, int node, int k)
{
    int ans = node;
    int i = 0;
    while (k)
    {
        if (k & 1)
        {
            ans = arr[ans][i];
            if (ans == -1)
                break;
        }
        k = k >> 1;
        i++;
    }

    return ans;
}

void dfs0 (vii &adj, vi &parents, int u, int p){
    parents[u] = p;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs0 (adj, parents, v, u);
    }
}

void dfs(vii &adj, vi &depths, int node, vector<bool> &visited)
{

    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            depths[child] = depths[node] + 1;
            dfs(adj, depths, child, visited);
        }
    }
}

void dfs2(vii &adj, vi &prefsum, int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs2(adj, prefsum, v, u);
        prefsum[u] += prefsum[v];
    }
}

void solve()
{
    int n;
    cin >> n;

    vi parent(n, -1);

    vii adj(n);

    rep(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs0(adj, parent, 0, -1);

    int lg = 22;
    vii arr(n, vi(lg, -1));
    rep(i, 0, n)
        arr[i][0] = parent[i];

    rep(j, 1, lg)
    {
        rep(i, 0, n)
        {
            if (arr[i][j - 1] != -1)
                arr[i][j] = arr[arr[i][j - 1]][j - 1];
            else
                arr[i][j] = -1;
        }
    }

    vi depths(n, 0);
    vector<bool> visited(n, false);
    dfs(adj, depths, 0, visited);

    vi prefsum(n, 0);

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int aa = a, bb = b;


        if (depths[a] < depths[b])
            swap(a, b);

        a = get_k(arr, a, depths[a] - depths[b]);

        int parent;

        if (a == b)
        {
            parent = a;
        }
        else{
            for (int i = lg - 1; i >= 0; i--)
            {
                if (arr[a][i] != arr[b][i])
                {
                    a = arr[a][i];
                    b = arr[b][i];
                }
            }
        
            parent = arr[a][0];
        }

        int ppparent = arr[parent][0];

        if (parent == aa)
        {
            prefsum[bb] += 1;

            if (ppparent != -1)
                prefsum[ppparent] -= 1;
        }
        else if (parent == bb)
        {
            prefsum[aa] += 1;
            if (ppparent != -1)
                prefsum[ppparent] -= 1;
        }
        else
        {
            prefsum[aa] += 1;
            prefsum[bb] += 1;
            prefsum[parent] -= 1;
            if (ppparent != -1)
                prefsum[ppparent] -= 1;
        }
    }

    // for (auto i: prefsum) cout << i << ' ';
    // cout << endl;


    dfs2(adj, prefsum, 0, -1);

    rep(i, 0, n)
    {
        cout << prefsum[i] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    while (tc--)
        solve();

    return 0;
}