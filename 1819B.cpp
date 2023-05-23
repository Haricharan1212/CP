// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

void solve()
{
    int n;
    cin >> n;

    vector<pi> a(n);
    int area = 0;
    int mh = 0, mw = 0;
    map<int, multiset<int>> m, mm;

    rep(i, 0, n)
    {
        cin >> a[i].first >> a[i].second;
        area += a[i].first * a[i].second;
        mh = max(mh, a[i].first);
        mw = max(mw, a[i].second);

        m[a[i].first].insert(a[i].second);
        mm[a[i].second].insert(a[i].first);
    }

    set<pi> ans;

    auto f = m, ff = mm;

    if (area % mh == 0)
    {
        int w = area / mh;
        int h = mh;
        int flag = 1;

        while (h > 0 && w > 0)
        {
            if (m[h].size())
            {
                int x = *--m[h].end();
                m[h].erase(--m[h].end());
                w -= x;
                continue;
            }

            if (mm[w].size())
            {
                int y = *--mm[w].end();
                mm[w].erase(--mm[w].end());
                h -= y;
                continue;
            }
            flag = 0;
            break;
        }
        if (flag)
        {
            ans.insert({mh, area / mh});
        }
    }

    m = f;
    mm = ff;
    if (area % mw == 0)
    {
        int w = mw;
        int h = area / mw;
        int flag = 1;

        while (h > 0 && w > 0)
        {
            if (m[h].size())
            {
                int x = *--m[h].end();
                m[h].erase(--m[h].end());
                w -= x;
                continue;
            }

            if (mm[w].size())
            {
                int y = *--mm[w].end();
                mm[w].erase(--mm[w].end());
                h -= y;
                continue;
            }
            flag = 0;
            break;
        }
        if (flag)
        {
            ans.insert({area / mw, mw});
        }
    }

    cout << ans.size() << endl;

    for (auto i : ans)
        cout << i.first << ' ' << i.second << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
