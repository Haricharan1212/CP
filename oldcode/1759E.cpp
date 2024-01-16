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
    ll n, h;
    cin >> n >> h;
    ll z = h;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;

    ll i = 0;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 2;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 2;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 3;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }

    ans = i;

    //////
    h = z;
    i = 0;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 2;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 3;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 2;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    ans = max(ans, i);

    ///////
    i = 0;
    h = z;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 3;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 2;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    h *= 2;
    for (; i < n; i++)
    {
        if (a[i] < h)
            h += a[i] / 2;
        else
            break;
    }
    ans = max(ans, i);

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
