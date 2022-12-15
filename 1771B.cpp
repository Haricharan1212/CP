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

#define vi vector<ll>
#define vii vector<vector<int>>

void solve()
{
    ll n, m;
    cin >> n >> m;

    map<ll, set<ll>> ma;

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        if (a > b)
            ma[a].insert(b);
        else
            ma[b].insert(a);
    }

    ll ans = 1;
    ll start = 0;
    for (ll i = 1; i < n; i++)
    {
        // cout << ans << ' ';

        if (ma[i].size() == 0)
        {
            ans += i - start + 1;
            continue;
        }
        ll num = *(--ma[i].end());

        if ((num < start))
        {
            ans += i - start + 1;
        }
        else
        {
            ans += i - (num + 1) + 1;
            start = num + 1;
        }
    }

    cout << ans << endl;
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
