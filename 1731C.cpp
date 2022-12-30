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

vector<ll> m(1e6, 0);

void solve()
{

    ll n;
    cin >> n;

    for (int i = 0; i < 4 * n; i++)
        m[i] = 0;
    m[0] = 1;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref = a;
    for (int i = 1; i < n; i++)
        pref[i] ^= pref[i - 1];

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += i + 1;
        for (int j = 0; j * j < 2 * n; j++)
            ans -= m[pref[i] ^ (j * j)];

        m[pref[i]]++;
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
