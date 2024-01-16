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

void solve()
{
    int n, s;
    cin >> n >> s;
    map<int, pi> m;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    rep(i, 0, n) rep(j, i + 1, n) m[a[i] + a[j]] = {i, j};

    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            int sum = a[i] + a[j];
            if (m.find(s - sum) != m.end())
            {
                pi p = m[s - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    cout << i + 1 << ' ' << j + 1 << ' ' << p.first + 1 << ' ' << p.second + 1 << '\n';
                    return;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
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
