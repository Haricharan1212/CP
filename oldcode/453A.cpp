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

// To find max, f(X < x) = f(X1 < x) * f(X2 < x) * f(X3 < x) * ... * f(Xn < x)
// = (x / a1) * (x / a2) * (x / a3) * ... * (x / an) = x^n / m^n

// P(x) = n x^(n - 1)/m^n
//  E(x) = n sum(x^n / m^n)

void solve()
{
    int m, n;
    cin >> m >> n;

    long double ans = 0;
    rep(i, 1, m + 1)
    {
        ans += i * (powl((long double)i / (long double)m, n) - pow(((long double)i - 1) / (long double)m, n));
    }

    cout << fixed << setprecision(30) << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
