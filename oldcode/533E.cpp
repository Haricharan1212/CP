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

bool check(string &x, string &y)
{

    int n = x.size();
    int m = y.size();
    if (n != m + 1)
        return false;

    int ind = m, indd = 0;

    // cout << x << " " << y << endl;

    rep(i, 0, m)
    {
        if (x[i] != y[i])
        {
            ind = i;
            break;
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (x[i] != y[i - 1])
        {
            indd = i;
            break;
        }
    }

    if (ind == indd)
        return true;
    return false;
}
void solve()
{
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int ans = 0;
    int f = 0;

    rep(i, 0, n) if (s[i] != t[i]) f++;

    rep(i, 0, n)
    {
        if (s[i] != t[i])
        {
            string a = s.substr(0, i + 1) + t.substr(i, n - i);
            string b = t.substr(0, i + 1) + s.substr(i, n - i);

            if (check(a, s) && check(a, t))
                ans++;
            if (check(b, s) && check(b, t))
                ans++;

            break;
        }
    }
    if (f == 1)
        ans = 2;

    cout << ans << endl;
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
