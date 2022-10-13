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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    pair<int, int> dp[n];

    dp[0] = make_pair(1, a[0]);
    dp[1] = a[1] > a[0] ? make_pair(2, a[1]) : make_pair(1, min(a[0], a[1]));
    for (int i = 2; i < n; i++)
    {
        dp[i] = (dp[i - 1].second < a[i]) ? make_pair(dp[i - 1].first + 1, a[i]) : dp[i - 1];
    }
    for (auto i : dp)
        cout << i.first << ' ' << i.second << "     ";
    cout << dp[n - 1].first;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //   cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
