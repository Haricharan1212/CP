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

const int N = 2e5; // limit for array size
int n;             // array size
int t[2 * N];

void build()
{
    for (int i = n - 1; i > 0; --i)
        t[i] = max(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r)
{ // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, t[l++]);
        if (r & 1)
            res = max(res, t[--r]);
    }
    return res;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < 2 * N; i++)
        t[i] = 0;

    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];

    rep(i, 0, n)
    {
        cin >> b[i];
        t[n + i] = b[i];
    }

    int m;
    cin >> m;
    map<int, int> razors;
    rep(i, 0, m)
    {
        int x;
        cin >> x;
        razors[x]++;
    }

    rep(i, 0, n) if (a[i] < b[i])
    {
        cout << "NO" << endl;
        return;
    }

    build();

    map<int, vector<int>> ma;
    rep(i, 0, n)
    {

        if (a[i] != b[i])
            ma[b[i]].push_back(i);
    }

    for (auto i : ma)
    {
        vi f = i.second;
        int num = razors[i.first];
        int numm = i.first;

        if (f.size() == 1)
        {
            if (num)
                continue;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }

        int start = 0;
        int count = 1;

        for (int i = 1; i < f.size(); i++)
        {
            // cout << start << ' ' << query(f[start], f[i] + 1) << ' ';
            // cout << f[start] << ' ' << f[i] << endl;
            if (query(f[start], f[i] + 1) <= numm)
                continue;
            else
            {
                count++;
                start = i;
            }
        }

        if (count <= num)
            continue;
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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
