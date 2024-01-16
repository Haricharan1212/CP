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

int l[1001][1001] = {0};

void initialize()
{

    l[0][0] = 1;
    for (int i = 1; i < 1001; i++)
    {
        l[i][0] = 1;
        for (int j = 1; j < i + 1; j++)
        {
            l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]) % mod1;
        }
    }
}

int nCr(int n, int r)
{
    // Return nCr
    return l[n][r];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int num = a[k];

    int f = 0;
    rep(i, 0, n) if (a[i] == num) f++;

    int count = 0;
    rep(i, 0, k)
    {
        if (a[i] == num)
        {
            count++;
        }
    }

    cout << nCr(f, count) % mod1 << endl;

    // cout << f << ' ' << count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    initialize();
    while (tc--)
    {
        solve();
    }

    return 0;
}
