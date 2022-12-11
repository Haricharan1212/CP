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
    ll n;
    cin >> n;

    vi a(n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            count++;
        }
        else
            ans += count;
    }
    vi b = a;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            break;
        }
    }
    ll anss = 0;
    count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            count++;
        }
        else
            anss += count;
    }
    ans = max(ans, anss);

    b = a;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (b[i] == 1)
        {
            b[i] = 0;
            break;
        }
    }

    anss = 0;
    count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            count++;
        }
        else
            anss += count;
    }
    ans = max(ans, anss);

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
