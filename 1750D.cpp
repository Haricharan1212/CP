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

const int N = 1e5 + 5;
bool prime[N + 1];

void sieve()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

void solve()
{

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll g = a[0];
    vector<ll> dp(n, 0);

    dp[0] = 1;

    int mod = 998244353;

    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] % a[i] != 0)
        {
            cout << 0 << endl;
            return;
        }

        dp[i] = dp[i - 1] * (a[i] == a[i - 1] ? m / a[i] : (m / a[i] - (m * a[i - 1]) / (a[i])));
        dp[i] %= mod;
    }

    for (auto i : dp)
        cout << i << ' ';
    cout << dp[n - 1] << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
