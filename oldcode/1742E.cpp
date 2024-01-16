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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref(n);
    pref[0] = a[0];
    for (ll i = 1; i < n; i++)
        pref[i] = a[i] + pref[i - 1];

    vector<ll> maxx(n);
    maxx[0] = a[0];
    for (ll i = 1; i < n; i++)
        maxx[i] = max(a[i], maxx[i - 1]);

    for (ll i = 0; i < q; i++)
    {
        ll q;
        cin >> q;
        if (q < a[0])
        {
            cout << 0 << ' ';
            continue;
        }
        ll ind = upper_bound(maxx.begin(), maxx.end(), q) - maxx.begin();

        cout << pref[ind - 1] << ' ';
    }

    cout << endl;
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
