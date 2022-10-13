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
    vector<ll> a(n);
    ll pref[n] = {0};

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    pref[0] = a[0];

    for (ll i = 1; i < n; i++)
        pref[i] = a[i] + pref[i - 1];

    ll ansss = 1e9;
    for (ll k = 0; k < n; k++)
    {
        ll i = pref[k];
        ll sum = 0;
        ll flag = 1;
        ll count = 0;
        ll ans = 0;
        for (ll j = 0; j < n; j++)
        {
            sum += a[j];
            count++;
            // cout << sum << ' ';
            if (sum == i)
            {
                sum = 0;
                ans = max(count, ans);
                count = 0;
            }
            if (sum > i)
            {
                sum = 0;
                flag = 0;
                break;
            }
        }
        // cout << ans << endl;
        if (flag && (sum == 0 || sum == i))
            ansss = min(ansss, ans);
        // cout << ansss << ' ';
    }
    if (ansss == 1e9)
        ansss = n;
    cout << ansss << endl;
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
