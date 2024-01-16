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

bool check(string &a, string &b, vi &c, int mid)
{
    set<int> s;
    rep(i, 0, mid)
    {
        s.insert(c[i]);
    }

    string ss = "";

    rep(i, 0, a.size()) if (s.find(i) == s.end()) ss += a[i];

    int i = 0, j = 0;

    while (i < ss.size() && j < b.size())
    {
        if (ss[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    return j == b.size();
}

void solve()
{
    string a;
    string b;

    cin >> a >> b;

    vi c(a.size());
    rep(i, 0, a.size())
    {
        cin >> c[i];
        c[i]--;
    }

    int l = 0, r = a.size();

    // cout << check(a, b, c, 0) << endl;
    // cout << check(a, b, c, 1) << endl;
    // cout << check(a, b, c, 2) << endl;
    // cout << check(a, b, c, 3) << endl;
    // cout << check(a, b, c, 4) << endl;
    // cout << check(a, b, c, 5) << endl;
    // cout << check(a, b, c, 6) << endl;

    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(a, b, c, mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
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
