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

void check(vii &adj, int node, vector<bool> &visited, string &s, string &ss, int &num)
{
    visited[node] = true;
    ss.push_back(s[node]);

    // cout << node << ' ' << ss << endl;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            check(adj, i, visited, s, ss, num);
        }
        else
        {
            int cnt = 1;
            // cout << ss << "123" << endl;
            string temp = ss;
            temp = temp[temp.size() - 1] + temp.substr(0, temp.size() - 1);

            while (temp != ss)
            {
                cnt++;
                temp = temp[temp.size() - 1] + temp.substr(0, temp.size() - 1);
            }

            num = cnt;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vi a(n);

    vii adj(n);

    rep(i, 0, n)
    {
        cin >> a[i];
        a[i]--;

        adj[a[i]].push_back(i);
        // adj[i].push_back(a[i]);
    }

    vector<bool> visited(n, false);

    int ans = 1;
    rep(i, 0, n)
    {
        if (!visited[i])
        {
            string ss = "";
            int num = 1;
            check(adj, i, visited, s, ss, num);

            // cout << num << 'h' << endl;
            if (num == 0)
                continue;
            ans = ans * num / __gcd(ans, num);
        }
    }

    cout << ans << endl;
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
