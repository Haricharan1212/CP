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

vi ss;

vi precomp(int n)
{
    vi ss;

    ss.push_back(0);
    for (int i = 1; i < n; i++)
        ss.push_back(i + ss[i - 1]);

    return ss;
}

int sqsum(int n)
{
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

int getprev(int n)
{
    if (n == 1)
        return 0;

    int row = lower_bound(ss.begin(), ss.end(), n) - ss.begin();
    int ind = n - ss[row - 1];

    ind--;
    row--;
    row--;

    ind = max(ind, 1LL);

    return ss[row] + ind;
}

int getnext(int n)
{
    if (n == 1)
        return 0;

    int row = lower_bound(ss.begin(), ss.end(), n) - ss.begin();
    int ind = n - ss[row - 1];

    row--;
    row--;

    ind = min(ind, row + 1);

    return ss[row] + ind;
}

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    ans += n * n;

    int l = getprev(n);
    int r = getnext(n);

    while (l > 0)
    {
        ans += sqsum(r) - sqsum(l - 1);
        l = getprev(l);
        r = getnext(r);
        // cout << ans << ' ';
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    ss = precomp(1e6 + 5);

    while (tc--)
    {
        solve();
    }

    return 0;
}
