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
        return num;
    }
};

void solve()
{

    pi a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second;

    Line l1 = {a, b};

    pi d;
    cin >> d.first >> d.second;

    int num = l1.check(d);

    if (num == 0)
        cout << "TOUCH" << endl;
    else if (num < 0)
        cout << "LEFT" << endl;
    else
        cout << "RIGHT" << endl;
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
