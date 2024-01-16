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

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    string z, b;
    cin >> z >> b;

    vector<ll> a;
    for (ll i = 0; i < n; i++)
        if (z[i] != b[i])
            a.push_back(i);

    if (a.size() % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    if (a.size() == 2 && a[0] + 1 == a[1])
    {
        if (x <= 2 * y)
            cout << x << endl;
        else
            cout << 2 * y << endl;
        return;
    }
    else
    {
        ll ans = ((ll)(a.size()) / 2) * y;
        cout << ans << endl;
    }
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
