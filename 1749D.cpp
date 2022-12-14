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

const int n = 1e5 + 5;
bool prime[n + 1];

void sieve()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[0] = false;
    prime[1] = false;
}
const int mod = 998244353;

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll prod = 1;
    ll pow = m;
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        pow *= m;
        pow %= mod;

        if (prime[i])
            prod *= i;

        ans += pow - (m / prod);
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    sieve();
    while (tc--)
    {
        solve();
    }

    return 0;
}
