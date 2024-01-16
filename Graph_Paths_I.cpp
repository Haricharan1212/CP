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

vii matrix_product (vii &a, vii &b){
    int n = a.size();
    vii res(n, vi(n, 0));

    rep (i, 0, n){
        rep (j, 0, n){
            rep (k, 0, n){
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }

    return res;
}

vii matrix_exp (vii a, int b){
    int n = a.size();
    vii res(n, vi(n, 0));

    rep (i, 0, n) res[i][i] = 1;

    while (b){
        if (b & 1) res = matrix_product (res, a);
        a = matrix_product (a, a);
        b >>= 1;
    }

    return res;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vii matr(n, vi(n, 0LL));

    rep (i, 0, m){
        int u, v;
        cin >> u >> v;
        u--, v--;

        matr[u][v]++;
    }

    vii res = matrix_exp (matr, k);
    cout << res[0][n - 1] << endl;

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