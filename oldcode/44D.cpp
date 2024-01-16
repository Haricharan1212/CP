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
#define float long double
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

struct Coord
{
    int x;
    int y;
    int z;
};

float dist(Coord a, Coord b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
}

void solve()
{
    int n;
    cin >> n;

    vector<Coord> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    float f = 1e9;

    rep(i, 1, n) rep(j, i + 1, n)
    {
        float d1 = dist(a[0], a[i]);
        float d2 = dist(a[0], a[j]);
        float d3 = dist(a[i], a[j]);

        f = min(f, (d1 + d2 + d3) / 2);
    }

    cout << fixed << setprecision(30) << f << endl;
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
