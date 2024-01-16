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

void primeFactors(int n, map<int, int> &m)
{
    while (n % 2 == 0)
    {
        m[2]++;
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            m[i]++;
            n = n / i;
        }
    }

    if (n > 2)
        m[n]++;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    int nums = 0, num = 0;

    map<int, int> m;
    rep(i, 0, n)
    {

        cin >> a[i];
        primeFactors(a[i], m);
    }

    for (auto i : m)
        nums += i.second / 2, num += i.second % 2;

    cout << nums + num / 3 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    // prime = sieve(1e4);

    while (tc--)
    {
        solve();
    }

    return 0;
}
