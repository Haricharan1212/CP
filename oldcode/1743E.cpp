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

struct T
{
    ll t1 = 0, t2 = 0, t = 0, t1a = 0, t2a = 0;
};

void solve()
{
    ll p1, t1, p2, t2;
    cin >> p1 >> t1 >> p2 >> t2;

    ll h, s;
    cin >> h >> s;

    T dp[h + p1 + p2 + 1];

    for (ll i = 1; i <= h + p1 + p2; i++)
    {
        if (i >= (p1 - s))
        {
            dp[i].t = dp[i - (p1 - s)].t1 + (t1 - dp[i - (p1 - s)].t1);
            dp[i].t1 = dp[i].t1a = 0;
            dp[i].t2 = dp[i].t2a = min(t2, dp[i - (p1 - s)].t2 + t1 - dp[i - (p1 - s)].t1);
        }
        if (i >= (p2 - s))
        {
            if (dp[i - (p2 - s)].t + (t2 - dp[i - (p2 - s)].t2) < dp[i].t)
            {
                dp[i].t = dp[i - (p2 - s)].t + (t2 - dp[i - (p2 - s)].t2a);
                dp[i].t1 = dp[i].t1a = min(t1, dp[i - (p2 - s)].t1a + t2 - dp[i - (p2 - s)].t2a);
                dp[i].t2 = dp[i].t2a = 0;
            }
            if (dp[i - (p2 - s)].t + (t2 - dp[i - (p2 - s)].t2) == dp[i].t)
            {
                dp[i].t = dp[i - (p1 - s)].t + (t1 - dp[i - (p1 - s)].t1);
                dp[i].t1a = 0;
                dp[i].t2a = min(t2, dp[i - (p1 - s)].t2 + t1 - dp[i - (p1 - s)].t1);
            }
        }

        if (i >= (p1 + p2 - s))
        {

            if (dp[i - (p1 + p2 - s)].t + max(t1 - dp[i - (p1 + p2 - s)].t1, t2 - dp[i - (p1 + p2 - s)].t2) < dp[i].t)
            {

                dp[i].t = dp[i - (p1 + p2 - s)].t + max(t1 - dp[i - (p1 + p2 - s)].t1, t2 - dp[i - (p1 + p2 - s)].t2);
                dp[i].t1 = dp[i].t1a = 0;
                dp[i].t2 = dp[i].t2a = 0;
            }
        }

        cout << i << ' ' << dp[i].t << ' ' << dp[i].t1 << ' ' << dp[i].t2 << endl;
    }

    ll t = dp[h].t;
    for (ll i = h; i <= h + p1 + p2; i++)
        t = min(t, dp[i].t);

    cout << t << endl;
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
