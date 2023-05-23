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

int check(string &s, int a)
{
    int count = 0;
    int m = s.size();
    rep(i, 0, m - 1)
    {
        if (s[i] == s[i + 1] && s[i] == a)
            count++, i++;
    }

    return count;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int min = 0, max = 0;

    rep(i, 0, n)
    {
        string s;
        cin >> s;

        int ones = 0, zeroes = 0;

        rep(i, 0, m)
        {
            if (s[i] == '1')
                ones++;
            else
                zeroes++;
        }

        int count = check(s, '1');
        // cout << max << ' ';
        // if (count >= m / 4)
        //     max += ones;
        // else
        //     max += (m - 2 * count) / 2;
        min += count + (ones - 2 * count);
        // cout << min << ' ';
        max += ones;
    }

    cout << min << ' ' << max;
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
