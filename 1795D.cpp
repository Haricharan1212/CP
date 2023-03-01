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

int modexp(long long x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

vector<bool> sieve(int n)
{
    // Time Complexity:- O(log(log(n)))

    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && 1LL * i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return is_prime;
}

int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
int modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);

    {
        // m is added to handle negative x
        int res = (x % M + M) % M;
        return res;
    }
}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    int ans = 1;

    for (int i = n / 6 + 1; i <= n / 3; i++)
    {
        ans *= i;
        ans %= mod2;
    }
    for (int i = 1; i <= n / 6; i++)
    {
        ans *= modInverse(i, mod2);
        ans %= mod2;
    }

    rep(i, 0, n / 3)
    {
        int arr[3] = {a[3 * i], a[3 * i + 1], a[3 * i + 2]};
        sort(arr, arr + 3);

        if (arr[0] == arr[1] && arr[1] == arr[2])
            ans *= 3;
        else if (arr[1] == arr[2])
        {
            ans *= 1;
        }
        else if (arr[0] == arr[1])
        {
            ans *= 2;
        }
        else
            ans *= 1;

        ans %= mod2;
    }

    cout << ans << endl;
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
