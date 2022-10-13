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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    if (k == 1)
    {
        cout << "YES" << endl;
        return;
    }

    for (int i = k - 1; i >= 1; i--)
    {
        a[i] -= a[i - 1];
    }

    for (int i = 1; i < k - 1; i++)
    {
        if (a[i] <= a[i + 1])
            continue;
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    ll num = a[1];
    if (a[1] * (n - k + 1) >= a[0])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
