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
    int n;
    cin >> n;
    deque<pair<ll, ll>> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i].first;

    for (int i = 0; i < n; i++)
        cin >> d[i].second;

    deque<pair<ll, ll>> dd;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i].second == 0)
            ans += d[i].first;
        else
            dd.push_back(d[i]);
    }

    while (dd.size() > 1)
    {
        if (dd[0].second > dd[dd.size() - 1].second)
        {
            dd[dd.size() - 2].first += dd[dd.size() - 1].second;
            ans += dd[dd.size() - 1].first;
            dd.pop_back();
        }
        else
        {
            dd[1].first += dd[0].second;
            ans += dd[0].first;
            dd.pop_front();
        }
    }
    if (dd.size() != 0)
        ans += dd[0].first;
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
