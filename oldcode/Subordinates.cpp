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

void check(vector<vector<int>> &children, int n, vi &ans, int num)
{
    // cout << children[num].size() << ' ';

    int f = children[num].size();
    for (int i = 0; i < children[num].size(); i++)
    {
        // if (ans[children[num][i]] == -1)
        {
            // cout << children[num][i];
            check(children, n, ans, children[num][i]);
        }
        f += ans[children[num][i]];
    }
    ans[num] = f;

    return;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    vector<vector<int>> children(n);
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        a[i]--;
        children[a[i]].push_back(i + 1);
    }

    vi ans(n, -1);

    check(children, n, ans, 0);

    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
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
