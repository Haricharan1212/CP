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

    map<int, pi> m;

    vi arr1, arr2;

    rep(i, 1, 101) arr1.push_back(i);
    rep(i, 1, 101) arr2.push_back(i << 7);

    rep(i, 1, 101) for (int j = 1; j < 101; j += 1) m[i ^ (j << 7)] = {i, j << 7};

    cout << "? ";

    for (auto i : arr1)
        cout << i << " ";
    cout << endl;

    int x;
    cin >> x;

    cout << "? ";

    for (auto i : arr2)
        cout << (i) << " ";

    cout << endl;

    int y;
    cin >> y;

    cout << "! ";
    cout << (((m[x ^ y]).first) ^ x) << endl;
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
