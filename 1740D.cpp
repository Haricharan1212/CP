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
    int m, n, k;
    cin >> m >> n >> k;

    vi a(k);
    rep(i, 0, k)
    {
        cin >> a[i];
    }

    int freespace = max((n - 1) * m - 1, (m - 1) * n - 1);

    reverse(a.begin(), a.end());

    set<int> s;

    int current = k;

    int index = 0;
    while (current != 0)
    {
        if (s.count(current))
            s.erase(current);
        else
        {
            while (a[index] != current)
            {
                s.insert(a[index]);
                index++;
            }
        }
        current--;

        if (s.size() > freespace)
        {
            cout << "TIDAK" << endl;
            return;
        }
    }

    cout << "YA" << endl;
    return;
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
