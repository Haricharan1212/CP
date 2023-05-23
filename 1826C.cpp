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

vi sieve(int n)
{
    vector<int> least_prime(n + 1, 0);

    least_prime[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;
            for (int j = i * i; j <= n; j += i)
                if (least_prime[j] == 0)
                    least_prime[j] = i;
        }
    }

    return least_prime;
}
vector<int> is_prime;

void solve()
{
    int n, m;
    cin >> n >> m;

    int f = is_prime[n];

    if (f <= m && f != 1)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    is_prime = sieve(1000000);
    while (tc--)
    {
        solve();
    }

    return 0;
}
