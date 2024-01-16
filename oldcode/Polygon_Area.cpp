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

// int ar(pi a, pi b, pi c)
// {
//     int area = b.first * c.second - b.second * c.first - a.first * c.second + a.second * c.first + a.first * b.second - a.second * b.first;

//     return abs(area);
// }

void solve()
{
    int n;
    cin >> n;

    vector<pi> points;

    // pi a, b;
    // cin >> a.first >> a.second >> b.first >> b.second;
    int area = 0;

    for (int i = 0; i < n; i++)
    {
        pi p;
        cin >> p.first >> p.second;
        points.push_back(p);
    }

    points.push_back(points[0]);

    for (int i = 0; i < n; i++)
    {
        area += points[i].first * points[i + 1].second - points[i + 1].first * points[i].second;
    }

    cout << abs(area) << endl;
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
