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
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    vi b = a;

    sort(a.begin(), a.end());
    int num = a[k - 1];

    vi f;
    int kcount = 0;
    rep(i, 0, n)
    {
        if (b[i] <= num)
        {
            f.push_back(b[i]);
        }
        if (b[i] == num)
            kcount++;
    }
    vi ff = f;
    int numcount = f.size() - k;

    rep(i, 1, f.size()) f[i] += f[i - 1];

    int ans = 1e18;

    int ks = 0;

    rep(i, 0, f.size())
    {
        if (ff[i] == num)
            ks++;
        int lsum = f[i];
        int rsum = f[f.size() - 1] - f[i];

        // cout << lsum << ' ' << rsum << ' ';
        // cout << ks << endl;

        if (lsum > rsum)
        {
            int nnum = ((lsum - rsum) / num);
            // cout << nnum << 'l' << endl;

            if (nnum < numcount)
            {
                lsum -= numcount * k;
                ans = max(ans, )
            }

            lsum -= nnum * num;
            int nn = numcount - nnum;
            int nnn = ceill((nn) / 2.0);
            rsum -= nnn * num;
            lsum -= (nn - nnn) * num;

            ans = min(ans, max(lsum, (rsum)));
        }
        else
        {
            int nnum = ((rsum - lsum) / num);
            // cout << nnum << 'h' << endl;

            rsum -= nnum * num;
            int nn = numcount - nnum;
            int nnn = ceill((nn) / 2.0);
            lsum -= nnn * num;
            rsum -= (nn - nnn) * num;
            ans = min(ans, max(lsum, (rsum)));
        }
    }
    cout << ans << endl;
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
