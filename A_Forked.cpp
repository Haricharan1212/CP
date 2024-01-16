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
    int a, b;
    cin >> a >> b;

    int xk, yk;
    cin >> xk >> yk;

    int xq, yq;
    cin >> xq >> yq;

    set <pi> s;
    int ans = 0;

    for  (int i = -1; i <= 1; i += 2)
    {
        for (int j = -1; j <= 1; j += 2)
        {
            int x = xk + i * a;
            int y = yk + j * b;

            {
                s.insert({x, y});
            }

            x = xk + i * b;
            y = yk + j * a;

            {
                s.insert({x, y});
            }

        }
    }

    set <pi> ss;

    for  (int i = -1; i <= 1; i += 2)
    {
        for (int j = -1; j <= 1; j += 2)
        {
            int x = xq + i * a;
            int y = yq + j * b;

            {
                ss.insert({x, y});
            }

    
            x = xq + i * b;
            y = yq + j * a;

            {
                ss.insert({x, y});
            }

        }
    }

    for (auto i : s)
    {
        if (ss.find(i) != ss.end())
        {
            // cout << i.first << " " << i.second << endl;
            ans++;
        }
    }

    cout << ans << endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}