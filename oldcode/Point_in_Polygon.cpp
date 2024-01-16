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

struct Line
{
    pi a, b;

    int check(pi c)
    {
        int num = (c.first - a.first) * (b.second - a.second) + (a.second - c.second) * (b.first - a.first);

        if (num == 0)
            return 0;
        else if (num > 0)
            return 1;
        else
            return -1;
    }

    bool intersect(pi p)
    {
        if (p.first >= min(a.first, b.first) && p.first <= max(a.first, b.first) && p.second >= min(a.second, b.second) && p.second <= max(a.second, b.second) && check(p) == 0)
            return true;
        else
            return false;
    }

    bool intersect(Line l)
    {
        int num1 = check(l.a);
        int num2 = check(l.b);

        int num3 = l.check(a);
        int num4 = l.check(b);

        bool fl1 = (max(a.first, b.first) >= min(l.a.first, l.b.first) && max(l.a.first, l.b.first) >= min(a.first, b.first));
        bool fl2 = (max(a.second, b.second) >= min(l.a.second, l.b.second) && max(l.a.second, l.b.second) >= min(a.second, b.second));

        if (num1 * num2 <= 0 && num3 * num4 <= 0 && fl1 && fl2)
            return true;
        else
            return false;
    }
};

int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pi> points(n);
    rep(i, 0, n)
    {
        cin >> points[i].first >> points[i].second;
    }
    vector<Line> lines(n);
    rep(i, 0, n)
    {
        lines[i].a = points[i];
        lines[i].b = points[(i + 1) % n];
    }

    rep(i, 0, m)
    {
        pi p;
        cin >> p.first >> p.second;

        map<int, int> m;

        rep(k, 0, 50)
        {
            int cnt = 0;
            Line l;
            l.a = p;
            l.b = {rand() % (2 * mod) - mod, rand() % (2 * mod) - mod};
            rep(j, 0, n)
            {
                if (lines[j].intersect(p) == true)
                {
                    cnt = -1;
                    break;
                }

                if (lines[j].intersect(l))
                    cnt++;

                if (l.intersect(points[j]))
                    cnt--;
            }

            m[cnt]++;
        }

        int mxpos = -1, mx = 0;
        for (auto i : m)
        {
            if (i.first != -1 && i.second > mx)
            {
                mx = i.second;
                mxpos = i.first;
            }
        }

        if (m[-1])
            cout << "BOUNDARY\n";
        else if (mxpos % 2 == 1)
            cout << "INSIDE\n";
        else
            cout << "OUTSIDE\n";
    }
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
