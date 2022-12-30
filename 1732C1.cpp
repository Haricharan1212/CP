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
}

void solve()
{

    int n, q;
    cin >> n >> q;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l, r;
    cin >> l >> r;
    ll sum = 0;
    ll x = 0;
    for (int i = 0; i < n; i++)
        sum += a[i], x ^= a[i];

    int val = sum - x;

    l = 0;
    r = n - 1;

    int l = 0;
    int sum, x = 0;

    for (int r = 0; r < n; r++)
    {
        sum += a[r];
        x ^= a[r];

        while (!(val == sum - x))
        {
            sum -= a[l];
            x ^= a[l];
            l++;
        }
    }

    cout << l + 1 << ' ' << r + 1 << endl;
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
