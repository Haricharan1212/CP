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

vi factorial;

int mx = 2e5 + 5;

// int l[mx][105] = {0};

vector<vector<int>> l(mx, vector<int>(105, 0));

void initialize()
{
    l[0][0] = 1;

    for (int i = 1; i < mx; i++)
    {
        l[i][0] = 1;
        for (int j = 1; j < min(100LL, i + 1); j++)
        {
            l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]) % mod1;
        }
    }
}

// Function to return the value of nCr
int nCr(int n, int r)
{

    if (r > n)
        return 0;
    // Return nCr
    return l[n][r];
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> s;

    // 1 2 3
    int ans = 0;

    rep(i, 0, n)
    {
        s.push_back(a[i]);
        int posses = s.size() - (upper_bound(s.begin(), s.end(), a[i] - (k + 1)) - s.begin()) - 1;

        if (posses < m - 1)
            continue;

        int tt = nCr(posses, m - 1);

        ans += tt;
        ans %= mod1;
    }

    cout << ans << endl;
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
