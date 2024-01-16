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

const int mod = 1e9 + 9;
const int mod2 = 1e9 + 7;

const int p = 3901;

int modexp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vi modinvs;

int gethas(vi &hash, int l, int r)
{
    if (l == 0)
        return hash[r];

    return (((hash[r] - hash[l - 1]) * modinvs[l]) % mod + mod) % mod;
}

vi gethash(string &s)
{
    int n = s.size();
    vi hash(n, 0);
    int prev = 1;
    rep(i, 0, n)
    {
        hash[i] = ((s[i] - 'a') * prev + (i == 0 ? 0 : hash[i - 1])) % mod;
        hash[i] = (hash[i] % mod + mod) % mod;
        prev *= p;
        prev %= mod;
    }

    return hash;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    modinvs = vector<int>(n + 1, 0);
    int inv = modexp(p, mod - 2);
    rep(i, 1, n + 1)
    {
        modinvs[i] = modexp(inv, i);
    }

    vi hash = gethash(s);

    int k;
    cin >> k;
    vector<string> a(k);
    set<int> ss;

    rep(i, 0, k)
    {
        cin >> a[i];
        ss.insert(gethash(a[i])[a[i].size() - 1]);
    };

    vi dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        rep(j, i, n)
        {
            if (ss.count(gethas(hash, i, j)))
            {
                dp[i] += dp[j + 1];
                dp[i] %= mod2;
            }
        }
    }

    // for (auto i : dp)
    //     cout << i << ' ';

    cout << dp[0] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //  cin >> tc;
    while (tc--)
        solve();

    return 0;
}