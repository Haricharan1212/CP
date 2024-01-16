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

bool check(vector<ll> a, ll k, ll c, ll d)
{
    int num = 0;
    int n = a.size();
    for (int i = 0; i < d; i++)
    {
        if (i % (k + 1) < n)
            num += a[i % (k + 1)];
    }

    if (num < c)
        return false;
    else
        return true;
}

void solve()
{
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> pref = a;

    for (ll i = 1; i < n; i++)
        pref[i] += pref[i - 1];

    if (pref[min(d - 1, n - 1)] >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    if (pref[0] * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }

    ll l = 0, r = n - 1;
    while (l != r)
    {
        ll m = (l + r + 1) / 2;
        if (check(a, m, c, d))
        {
            l = m;
        }
        else
            r = m - 1;
    }

    cout << r << endl;
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
