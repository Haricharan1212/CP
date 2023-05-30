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

vi fib;
vi preffib;

void precomp()
{
    fib = {1, 1};

    rep(i, 2, 1000)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        if (fib[i] > 1e9)
            break;
    }
    vi preffib = fib;

    rep(i, 1, preffib.size())
    {
        preffib[i] += preffib[i - 1];
    }
}

void solve()
{
    int k;
    cin >> k;

    vi a(k);
    int sum = 0;
    rep(i, 0, k)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    if (bsearch(preffib.begin(), preffib.end(), sum) == preffib.end())
    {
        cout << 0 << endl;
        return;
    }

    // while (a.size())
    // {
    //     int num = a[a.size() - 1];
    // }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    precomp();

    while (tc--)
    {
        solve();
    }

    return 0;
}
