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

struct S
{
    int mn = -1e9;
    int mx = 1e9;
};

const int N = 1e5; // limit for array size
int n;             // array size
S t[2 * N];
void build()
{
    for (int i = n - 1; i > 0; --i)
    {
        t[i].mn = min(t[i << 1].mn, t[i << 1 | 1].mn);
        t[i].mx = min(t[i << 1].mx, t[i << 1 | 1].mx);
    }
}

int querymn(int l, int r)
{ // sum on interval [l, r)
    int mn = 1e9;
    int mx = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            mn = min(t[l++].mn, mn);
            mx = max(t[l++].mx, mx);
        }
        if (r & 1)
        {
            mn = min(t[--r].mn, mn);
            mx = max(t[--r].mx, mx);
        }
    }
    return mn;
} // cin inputs from index t + n + i, then build, then modify

int querymx(int l, int r)
{ // sum on interval [l, r)
    int mn = 1e9;
    int mx = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            mn = min(t[l++].mn, mn);
            mx = max(t[l++].mx, mx);
        }
        if (r & 1)
        {
            mn = min(t[--r].mn, mn);
            mx = max(t[--r].mx, mx);
        }
    }
    return mx;
} // cin inputs from index t + n + i, then build, then modify

void solve()
{
    int n;
    cin >> n;

    vi a(n), b(n);
    int x, y;
    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] == 1)
            x = i;
    }

    rep(i, 0, n)
    {
        cin >> b[i];
        if (b[i] == 1)
            y = i;
    }

    vi prefa = a, prefb = b;

    rep(i, 1, n)
    {
        prefa[i] = max(prefa[i], prefa[i - 1]);
        prefb[i] = max(prefb[i], prefb[i - 1]);
    }

    int ans = 0;
    int nm = 0;
    map<int, int> m, mm;

    int f = 1, g = 1;

    vi aa(n), bb(n, 0);

    rep(i, 0, n)
    {
        cout << ans << ' ';
        if (i < min(x, y))
        {
            ans += i + 1;
        }
        else if (i >= min(x, y) && i < max(x, y))
            ans += i - min(x, y);
        else if (i == max(x, y))
        {
            for (int j = i; j >= 0; j--)
            {
                m[a[j]]++;
                mm[b[j]]++;

                while (m[f])
                    f++;
                while (mm[g])
                    g++;
                aa[f]++;
                bb[g]++;

                if (f == g)
                    nm++;
            }
            ans += nm;
        }
        else
        {
            m[a[i]]++;
            mm[b[i]]++;

            while (m[f])
            {
                f++;
            }

            while (mm[g])
                S
                    g++;

            ans += i - max(x, y);
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
