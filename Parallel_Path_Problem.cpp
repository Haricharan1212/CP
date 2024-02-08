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
    pi x, y, z;
    cin >> x.first >> x.second >> y.first >> y.second >> z.first >> z.second;
    if ((x.first == y.first && x.first == z.first) || (x.second == y.second && x.second == z.second))
    {
        cout << 1 << endl;
        return;
    }
    // check if they form L shape

    if ((x.first == y.first && y.second == z.second) || )
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