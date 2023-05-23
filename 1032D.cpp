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

long double f(long double a, long double b, long double c, long double x, long double y)
{
    return a * x + b * y + c;
}

long double dist(long double x, long double y, long double z, long double w)
{
    return sqrtl((x - y) * (x - y) + (z - w) * (z - w));
}

void solve()
{
    long double a, b, c;
    cin >> a >> b >> c;

    long double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (f(a, b, c, x1, y2) * f(a, b, c, x2, y1) >= 0 || a < 1e-9 || b < 1e-9)
    {
        cout << abs(x1 - x2) + abs(y1 - y2) << endl;
        return;
    }

    long double ya = y1;
    long double xa = (-c - b * ya) / a;
    long double xb = x2;
    long double yb = (-c - a * xb) / b;

    long double d1 = dist(x1, xa, y1, ya) + dist(xa, xb, ya, yb) + dist(xb, x2, yb, y2);

    long double xaa = x1;
    long double yaa = (-c - a * xaa) / b;
    long double ybb = y2;
    long double xbb = (-c - b * ybb) / a;

    long double d2 = dist(x1, xaa, y1, yaa) + dist(xaa, xbb, yaa, ybb) + dist(xbb, x2, ybb, y2);
    long double dd = min(d1, d2);

    cout << fixed << showpoint;
    cout << setprecision(30) << dd << endl;
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
