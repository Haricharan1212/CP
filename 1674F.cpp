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
#define pi pair<int, int>
#define ordered_set tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    int arr[n][m];
    ordered_set s;
    rep(i, 0, n)
    {
        string ss;
        cin >> ss;

        rep(j, 0, m)
        {
            arr[i][j] = ss[j];
            if (arr[i][j] == '*')
                s.insert({j, i});
        }
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (arr[x][y] == '.')
        {
            arr[x][y] = '*';
            s.insert({y, x});
        }
        else
        {
            arr[x][y] = '.';
            s.erase({y, x});
        }

        int num = (int)s.size() - 1LL;
        if (num == -1)
        {
            cout << 0 << endl;
            continue;
        }
        int xx = num % n;
        int yy = num / n;
        // cout << xx << ' ' << yy << ' ';

        int numm = s.order_of_key({yy, xx});
        if (s.find({yy, xx}) != s.end())
            numm++;
        // cout << numm << ' ';

        cout << num - numm + 1 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
