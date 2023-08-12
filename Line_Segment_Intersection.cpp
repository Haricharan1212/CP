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

void solve()
{
    Line l1, l2;
    cin >> l1.a.first >> l1.a.second >> l1.b.first >> l1.b.second;
    cin >> l2.a.first >> l2.a.second >> l2.b.first >> l2.b.second;

    if (l1.intersect(l2) && l2.intersect(l1))
        cout << "YES\n";
    else
        cout << "NO\n";
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
