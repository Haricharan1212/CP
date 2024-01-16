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

#define float long double

bool comp(pi &a, pi &b)
{
    float x = atan2l(a.first, b.first);
    float y = atan2l(a.second, b.second);

    // if (abs(x - y) < 1e-7)
    // {
    //     return make_pair(abs(a.first), abs(a.second)) < make_pair(abs(b.first), abs(b.second));
    // }

    return x < y;
}

void solve()
{

    int n;
    cin >> n;

    vector<pi> points(n);

    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    sort(points.begin(), points.end());
    pi f = points[0];

    vector<pi> b;
    rep(i, 1, n) b.push_back({points[i].first - f.first, points[i].second - f.second});
    points = b;

    sort(points.begin(), points.end(), comp);

    for (auto i : points)
        cout << i.first << ' ' << i.second << endl;

    vector<pi> hull;
    hull.push_back({0, 0});

    for (int i = 0; i < (int)points.size(); i++)
    {
        pi a = hull[hull.size() - 1];
        pi b = points[i];
        pi c = points[(i + 1) % ((int)points.size())];

        if (i == (int)(points.size() - 1))
        {
            c = {0, 0};
        }

        int cross = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
        cout << cross << i << 'x';

        if (cross >= 0)
            continue;
        else
            hull.push_back(b);
    }

    // cout << endl;

    cout << hull.size() << endl;

    for (auto i : hull)
        cout << i.first + f.first << ' ' << i.second + f.second << endl;
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
