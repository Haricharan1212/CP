// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

ll mod = 998244353;

ll arr[62][62] = {0};

void printPascal(ll n)
{
    for (ll line = 0; line < n; line++)
    {
        for (ll i = 0; i <= line; i++)
        {
            if (line == i || i == 0)
                arr[line][i] = 1;
            else
                arr[line][i] = arr[line - 1][i - 1] +
                               arr[line - 1][i];
            arr[line][i] = (arr[line][i] + mod) % mod;
        }
    }
}

ll alex(ll n)
{
    if (n == 2)
        return 1;
    else
    {
        return (arr[n - 1][n / 2] + (arr[n - 2][(n - 2) / 2] - alex(n - 2) - 1) + mod) % mod;
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll num = alex(n);
    num = num % mod;
    num += mod;
    ll ans = (arr[n][n / 2] - 1 - num);
    ans = ans % mod;
    ans += mod;
    cout << num % mod << ' ' << ans % mod << ' ' << 1 << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll tc = 1;
    cin >> tc;
    printPascal(62);
    while (tc--)
    {
        solve();
    }

    return 0;
}
