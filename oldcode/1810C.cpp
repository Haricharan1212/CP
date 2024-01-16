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

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    int f = n;

    vi a(n);
    si s;
    rep(i, 0, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    sort(a.begin(), a.end());

    int cost = 0;

    a.empty();

    for (auto i : s)
    {
        a.push_back(i);
    }

    n = a.size();

    int costmin = 1e9;
    int current = 0;

    vi b(n);
    b[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] + 1 == a[i + 1])
        {
            b[i] = b[i + 1] + 1;
        }
        else
        {
            b[i] = 0;
        }
    }

    rep(i, 1, n)
    {
        if (a[i] != a[i - 1])
        {
            current += max(0LL, a[i] - (a[i - 1] + 1));
            costmin = min(current * d + c * (n - 1 - i - b[i]), costmin);
        }
    }

    cout << costmin << endl;
    cout << d * (f - s.size()) + costmin << endl;
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
