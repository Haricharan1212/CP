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

void print(int a, int b)
{
    cout << a + 1 << " " << b + 1 << endl;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    int ind;
    int maxind;
    int ind2;
    rep(i, 0, n)
    {
        cin >> a[i];

        if (a[i] == n)
            maxind = i;

        if (a[i] == 2)
            ind2 = i;

        if (a[i] == 1)
            ind = i;
    }

    if (ind < maxind && maxind < ind2)
    {
        print(0, 0);
    }
    else if (ind < ind2 && ind2 < maxind)
    {
        print(ind2, maxind);
    }
    else if (maxind < ind && ind < ind2)
    {
        print(maxind, ind);
    }
    else if (ind > maxind && maxind > ind2)
    {
        print(0, 0);
    }
    else if (ind > ind2 && ind2 > maxind)
    {
        print(ind2, maxind);
    }
    else
        print(maxind, ind);
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