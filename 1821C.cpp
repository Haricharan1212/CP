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

int f(string &s, char c, int n)
{
    if (s.find(c) == string::npos)
        return 1e9;
    vi f;
    rep(i, 0, n) if (s[i] == c) f.push_back(i);

    int z = 0;

    rep(i, 0, f.size() - 1)
        z = max(z, f[i + 1] - f[i] - 1);

    z = max(z, f[0]);
    z = max(z, n - f[f.size() - 1] - 1);

    // cout << c << z << endl;

    if (z == 0)
        return 0;

    return floorl(log2l(z)) + 1;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int ans = 1e9;

    for (char c = 'a'; c <= 'z'; c++)
    {
        ans = min(ans, f(s, c, n));
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
