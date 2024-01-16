// Chahel
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx2,fma")
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;
double eps = 1e-3;
double ep = 1e-8;
#define rep(i, n) for (ll i = 0, _n = (ll)(n); i < _n; i++)
#define endl '\n' // comment out for interactive problems

// 1 : bitwise AND
// 2 : bitwise OR
// 3 : bitwise XOR
// 4: addition
// 5: multiplication modulo (10^9+7)
// 6: exponentiation modulo (10^9+7)

ll op1, op2;

ll power(ll n, ll k, ll m = LLONG_MAX)
{
    n = n % m;
    if (k == 0)
        return 1;
    ll res = power(n, k / 2, m) % m;
    if (k % 2 == 0)
        return ((ll)1 * res * res) % m;
    else if (k % 2 != 0)
        return ((ll)1 * (res * res) % m * n) % m;
    return 0;
}

ll opp1(ll a, ll b)
{
    if (op1 == 1)
    {
        return a & b;
    }
    else if (op1 == 2)
    {
        return a | b;
    }
    else if (op1 == 3)
    {
        if (a == 0 && b == 0)
            return 0;
        return a ^ b;
    }
    else if (op1 == 4)
    {
        return (a + b);
    }
    else if (op1 == 5)
    {
        return (a * b) % mod;
    }
    else if (op1 == 6)
    {
        return power(a, b, mod);
    }
    return 0;
}

ll opp2(ll a, ll b)
{
    if (op2 == 1)
    {
        return a & b;
    }
    else if (op2 == 2)
    {
        return a | b;
    }
    else if (op2 == 3)
    {
        return a ^ b;
    }
    else if (op2 == 4)
    {
        return (a + b);
    }
    else if (op2 == 5)
    {
        return (a * b) % mod;
    }
    else if (op2 == 6)
    {
        return power(a, b, mod);
    }
    return 0;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll num = (1 << n);
    vector<ll> a[n + 1];
    rep(i, num)
    {
        ll x;
        cin >> x;
        a[n].push_back(x);
    }

    cin >> op1 >> op2;
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j < (1 << i); j++)
        {
            if ((n - i) % 2 == 1)
            {
                a[i].push_back(opp1(a[i + 1][2 * j], a[i + 1][2 * j + 1]));
            }
            else
            {
                a[i].push_back(opp2(a[i + 1][2 * j], a[i + 1][2 * j + 1]));
            }
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    rep(i, q)
    {
        ll idx, val;
        cin >> idx >> val;
        idx--;
        a[n][idx] = val;
        for (ll j = n - 1; j >= 0; j--)
        {
            if (idx % 2 == 1)
            {
                idx--;
            }
            if ((n - j) % 2 == 1)
            {
                a[j][idx / 2] = opp1(a[j + 1][idx], a[j + 1][idx + 1]);
            }
            else
            {
                a[j][idx / 2] = opp2(a[j + 1][idx], a[j + 1][idx + 1]);
            }
            idx /= 2;
        }
        cout << a[0][0] << endl;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}