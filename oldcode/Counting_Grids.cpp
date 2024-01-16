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

int mod = 1e9 + 7;

int binexp (int b){
    int a = 2;
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
    int n;
    cin >> n;
    int ans;

    if (n == 1)
        cout << 2 << endl;
    else if (n%2 == 0){
        ans = binexp ((n * n) / 4) + (binexp ((n * n) / 2 - 1) - binexp ((n * n) / 4 - 1)) + (binexp (n * n - 2) - binexp (n * n/2 - 2));
        cout << ans % mod << endl;
    }
    else{
        int a = binexp (((n - 1) * (n - 1))/4 + (n + 1)/2);
        int b = binexp(n * (n - 1)/2 + (n + 1)/2);
        int c = binexp(n * n);

        ans = a + (b - a) * binexp (mod - 2) + (c - b) * binexp ((mod - 3));
        ans %= mod;
        ans += mod;

        cout << ans % mod << endl;
    }


}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();

    return 0;
}