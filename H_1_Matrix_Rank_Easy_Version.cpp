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

const int mod = 998244353;

int modexp (int x, int n, int mod)
{
    n %= mod - 1;
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int modinv (int x, int mod)
{
    return modexp(x, mod - 2, mod);
}

void solve()
{
    // Product_{j=0..k-1} (2^n - 2^j)^2/(2^k - 2^j)

    int n, p, K;
    cin >> n >> p >> K;

    vi pows(K + 1, 0), powss(K + 1, 0);
    int modinv2 = modinv(p, mod);
    pows[0] = 1;
    rep (i, 1, K + 1){
        pows[i] = (pows[i - 1] * modinv2) % mod;
    }
    
    rep (i, 1, K + 1) 
        powss[i] = modinv (modexp (p, i, mod) - 1, mod);

    int powtwo = modexp(p, n, mod);

    rep (k, 0, K + 1){
        int cpow = 1;

        int ans = 1;
        rep (j, 0, k){
            ans *= (powtwo - cpow);
            ans = (ans % mod + mod) % mod;
            ans *= (powtwo - cpow);
            ans = (ans % mod + mod) % mod;

            int d = (pows[j] * powss[k - j]) % mod;
            ans *= d;
            ans = (ans % mod + mod) % mod;

            cpow *= p;
            cpow %= mod;
        }

        cout << ans << " ";
    }



}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}