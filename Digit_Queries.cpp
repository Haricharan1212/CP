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

#define int unsigned long long int
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
    int q;
    cin >> q;

    vi prep(18);
    prep[0] = 0;
    for (int i = 1; i < 18; i++)
        prep[i] = 9 * ((ll)powl(10, i - 1)) * (i);

    for (int i = 1; i < 18; i++)
        prep[i] += prep[i - 1];

    // for (auto x : prep)
    //     cout << x << ' ';

    while (q--)
    {
        int a;
        cin >> a;

        int digits = lower_bound(prep.begin(), prep.end(), a) - prep.begin();

        a -= prep[digits - 1] + 1;
        int f = a / digits;
        int numm = a % digits;

        // cout << digits << ' ' << f << ' ' << numm << endl;

        int num = f + ((ll)powl(10, digits - 1));

        string s = to_string(num);
        cout << s[numm] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    while (tc--)
    {
        solve();
    }

    return 0;
}
