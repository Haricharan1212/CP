// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

int modexp(int x, int n, int m)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

vi factorial;

int mod = 1e9 + 7;

void precompute(int n)
{
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (factorial[i - 1] * i) % mod;
}

void solve()
{
    string s;
    cin >> s;

    vi freq(26, 0);

    for (auto i : s)
        freq[i - 'a']++;

    int n = s.size();

    int ans = factorial[n];

    for (auto i : freq)
        ans = (ans * modexp(factorial[i], mod - 2, mod)) % mod;

    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;

    precompute(1e6 + 5);

    while (tc--)
        solve();

    return 0;
}
