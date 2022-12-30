// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

const ll mod = 998244353, inv = (mod + 1) / 2;

void add(ll &x, ll y)
{
    (x += y) >= mod && (x -= mod);
}

void solve()
{
    int n;
    map<ll, ll> s;
    ll tot, mul = 1, ts = 1;

    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll x;
            cin >> x;
            add(s[x + tot], ts);
        }
        else if (op == 2)
        {
            ll x;
            cin >> x;
            tot += x;
        }
        else if (tot <= 2e5)
        {
            if (tot == 0)
                mul = mul * 2 % mod, ts = ts * inv % mod;
            else
            {
                for (ll i = tot + 2e5; i > tot; i--)
                    add(s[i + tot], s[i]);
                tot *= 2;
            }
        }
    }
    ll res = 0;
    for (auto i : s)
        if (i.first > tot)
            add(res, i.second);
    res = res * mul % mod;
    cout << res;

    return;
}
int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
