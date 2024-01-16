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

const int mod = 1e9 + 7;

int binexp (int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;

    rep (i, 0, n){
        ans += binexp (m, __gcd(i, n));
        ans %= mod;
    }

    cout << (ans * binexp (n, mod - 2)) % mod << endl;
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