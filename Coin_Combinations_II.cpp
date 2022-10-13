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
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> arr(x + 1, 0);
    arr[0] = 1;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= x; j++)
            if (j >= a[i])
                arr[j] += arr[j - a[i]], arr[j] %= (int)(1e9 + 7);
    }

    cout << arr[x] % (ll)(1e9 + 7) << endl;
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
