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

template <typename T>
vector<T> slicing(vector<T> const &v,
                  int X, int Y)
{

    // Begin and End iterator
    auto first = v.begin() + X;
    auto last = v.begin() + Y + 1;

    // Copy the element
    vector<T> vector(first, last);

    // Return the results
    return vector;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    int maxind;
    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] == n)
            maxind = i;
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    if (maxind == 0)
    {
        rep(i, 0, n) if (a[i] == n - 1) maxind = i;

        pi f = {-1, 1e9};

        rep(i, 0, maxind) f = max(f, {a[i], i});

        cout << f.second;

        for (auto i : slicing(a, maxind, n - 1))
            cout << i << ' ';
        for (auto i : slicing(a, f.second, maxind - 1))
            cout << i << ' ';
        for (auto i : slicing(a, 0, f.second - 1))
            cout << i << ' ';

        cout << endl;
    }

    else
    {
        cout << "F" << endl;
    }
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
