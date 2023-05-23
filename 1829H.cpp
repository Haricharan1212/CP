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
    vector<vi> bits(n, vi(6, 0));
    rep(i, 0, n)
    {
        cin >> a[i];

        int temp = a[i];
        for (int j = 0; j < 6; j++)
        {
            bits[i][j] = temp % 2;
            temp /= 2;
        }
    }

    vector<bool> ff;
    rep(i, 0, 6 - k) ff.push_back(0);
    rep(i, 0, k) ff.push_back(1);

    do
    {

        for (int i = 0; i < 6; i++)
        {
            set<int> ss;
            if (ff[i] == 1)
            {
                rep(i, 0, n)
            }
        }

        ff = next_permutation(ff.begin(), ff.end());
    } while (next_permutation(ff.begin(), ff.end()));
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
