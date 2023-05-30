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

const int N = 3e5; // limit for array size
int n;             // array size
int t[2 * N];
void build()
{
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}
void modify(int p, int value)
{ // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}
int query(int l, int r)
{ // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
} // cin inputs from index t + n + i, then build, then modify

void solve()
{
    int q;
    cin >> n >> q;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        t[n + i] = a[i];
    }

    build();

    rep(_, 0, q)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            modify(b - 1, c);
        }
        else
        {
            cout << query(b - 1, c) << "\n";
        }
    }
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
