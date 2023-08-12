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

int getarea(vector<pi> points)
{
    int area = 0;
    int n = points.size();

    points.push_back(points[0]);

    for (int i = 0; i < n; i++)
    {
        area += points[i].first * points[i + 1].second - points[i + 1].first * points[i].second;
    }

    return abs(area);
}

int bpts(vector<pi> points)
{
    int n = points.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int dx = abs(points[i].first - points[(i + 1) % n].first);
        int dy = abs(points[i].second - points[(i + 1) % n].second);

        ans += __gcd(dx, dy);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> points;

    for (int i = 0; i < n; i++)
    {
        pi p;
        cin >> p.first >> p.second;
        points.push_back(p);
    }

    int area = getarea(points);
    int bp = bpts(points);
    int x = (area - bp) / 2 + 1;

    cout << x << ' ' << bp << endl;
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
