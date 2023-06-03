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

    int l, r;
    cin >> l >> r;

    int num = 0;
    int ll = l;

    while (ll <= r)
    {
        num++;
        ll = ll << 1;
    }

    int ans = 0;

    cout << num << ' ';
    num--;

    int lmin = l;
    int lmax = r / (1 << num);

    ans += lmax - lmin + 1;
    // cout << ans << endl;
    int pow3 = (1 << (num - 1)) * 3;

    // cout << pow3 << 'x' << endl;

    if (l * pow3 <= r)
    {
        int lmmin = l;
        int lmmax = r / (pow3);

        ans += (lmmax - lmmin + 1) * (num);
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
