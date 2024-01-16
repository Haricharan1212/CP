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

const int p = 3901;

int modexp (int a, int b)
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

int gethas (vi &hash, int l, int r)
{
    if (l == 0)
        return hash[r];

    return (((hash[r] - hash[l - 1]) * modinvs[l]) % mod + mod) % mod  ;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    modinvs = vector <int> (n + 1, 0);
    int inv = modexp(p, mod - 2);

    rep (i, 1, n + 1){
        modinvs[i] = modexp (inv, i);
    }

    vi hash (n, 0);

    int prev = 1;

    rep (i, 0, n){
        hash[i] = ((s[i] - 'a') * prev + (i == 0? 0: hash[i - 1])) % mod;
        hash[i] = (hash[i]% mod + mod) % mod;
        prev *= p;
        prev %= mod;
    }

    rep (g, 1, n + 1){
        int hasha = gethas (hash, 0, g - 1);

        int flag = 1;

        for (int j = 0; j + g <= n; j += g){
            int hashb = gethas (hash, j, j + g - 1);
            if (hasha != hashb){
                flag = 0;
                break;
            }
        }

        if (n%g != 0 && gethas (hash, 0, (n) % g - 1) != gethas (hash, (n / g) * g, n - 1)) flag = 0;

        if (flag)
            cout << g << " ";
    }


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