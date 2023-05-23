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

void addEdge(vector<int> adj[], int x,
             int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfs(vector<int> adj[], int node, int l,
         int p, int lvl[], int par[])
{
    lvl[node] = l;
    par[node] = p;

    for (int child : adj[node])
    {
        if (child != p)
            dfs(adj, child, l + 1, node, lvl, par);
    }
}

int LCA(int a, int b, int par[], int lvl[])
{
    if (lvl[a] > lvl[b])
        swap(a, b);

    int diff = lvl[b] - lvl[a];

    while (diff != 0)
    {
        b = par[b];
        diff--;
    }

    if (a == b)
        return a;

    while (a != b)
        a = par[a], b = par[b];

    return a;
}

deque<int> printPath(vector<int> adj[], int a, int b, int n)
{
    int lvl[n + 1];

    int par[n + 1];

    dfs(adj, 1, 0, -1, lvl, par);

    int lca = LCA(a, b, par, lvl);

    deque<int> path;

    while (a != lca)
        path.push_back(a), a = par[a];

    path.push_back(a);

    vector<int> temp;

    while (b != lca)
        temp.push_back(b), b = par[b];

    reverse(temp.begin(), temp.end());

    for (int x : temp)
        path.push_back(x);

    return path;
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> a(n - 1);
    map<pi, int> ans;

    vector<int> adj[n];

    set<pi> notdone;

    rep(i, 0, n - 1)
    {
        pi x;
        cin >> x.first >> x.second;
        if (x.first > x.second)
            swap(x.first, x.second);
        x.first--;
        x.second--;
        a[i] = x;
        ans[a[i]] = -1;
        addEdge(adj, a[i].first, a[i].second);
        notdone.insert(a[i]);
    }

    map<int, vi, greater<int>> m;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    // printPath(adj, a, b, n);

    for (auto &i : m)
    {
        if (i.second.size() > 2)
        {
            for (auto &j : ans)
            {
                if (j.second == -1)
                {
                    ans[j.first] = i.first;
                }
            }
        }
        else if (i.second.size() <= 1)
            continue;
        else
        {
            deque<int> path = printPath(adj, i.second[0], i.second[1], n - 1);
            set<pi> current;

            rep(i, 0, path.size() - 1)
            {
                current.insert({path[i], path[i + 1]});
            }

            for (auto &j : ans)
            {
                if (j.second == -1 && current.count(j.first) == 0)
                {
                    ans[j.first] = i.first;
                    notdone.erase(j.first);
                }
            }
            auto num = m.find(i.first);

            while (!notdone.empty())
            {
                num++;
                int x = (*num).first;
                vi temp = (*num).second;
                if (temp.size() > 2)
                {
                    for (auto &j : notdone)
                    {
                        ans[j] = i.first;
                    }
                }
                else if (temp.size() <= 1)
                    continue;
                else
                {
                    while (*path.begin() != temp[0] && *path.begin() != temp[1])
                    {
                        pi f = {path.front(), path[1]};
                        if (f.first > f.second)
                            swap(f.first, f.second);
                        ans[f] = x;
                        notdone.erase(f);
                        path.pop_front();
                    }
                    while (*path.end() != temp[0] && *path.end() != temp[1])
                    {
                        pi f = {path.back(), path[path.size() - 2]};
                        if (f.first > f.second)
                            swap(f.first, f.second);
                        ans[f] = x;
                        notdone.erase(f);
                        path.pop_back();
                    }
                }
            }
            break;
        }
    }

    for (auto i : a)
        cout << ans[i] << endl;
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
