// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

int mod1 = 1e9 + 7;

void dfs(vii &adj, int node, vb &visited, vi &x, vb &flag)
{
    visited[node] = true;
    map<int, vi> m;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dfs(adj, child, visited, x, flag);
            m[x[child]].push_back(child);
        }
    }

    int cnt = 0;
    x[node] = 127;
    int ind = 99;
    for (auto i : m)
    {
        ind += 5;
        ind %= mod1;

        int num = i.first * i.second.size();
        num %= mod1;
        num *= (i.second.size() * ind) % mod1;

        int numm = i.first * i.first;
        numm %= mod1;
        numm *= (i.second.size() * ind) % mod1;

        x[node] += (numm + num) % mod1;
        x[node] %= mod1;

        // if (i.second.size() % 2)
        // {
        //     flag[node] = 0;
        //     return;
        // }
        if (i.second.size() % 2 == 1)
            cnt++;
    }

    if (cnt > 1)
    {
        flag[node] = 0;
        return;
    }

    if (cnt == 0)
    {
        flag[node] = 1;
    }

    if (cnt == 1)
    {
        for (auto i : m)
        {
            if (i.second.size() % 2 == 1)
            {
                flag[node] = flag[i.second[0]];
                return;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vii adj(n);

    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vb visited(n, false);
    vi x(n, 1);
    // bool flag = true;
    vb check(n, false);
    vb flag(n, true);
    dfs(adj, 0, visited, x, flag);

    // for (auto i : x)
    // {
    //     cout << i << ' ';
    // }

    if (flag[0])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
