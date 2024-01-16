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
    int n;
    cin >> n;
    set<int> s;
    int current = 1;
    rep(i, 0, n) s.insert(i + 1);

    while (s.size())
    {
        int next = *s.upper_bound(current);
        cout << next << ' ';
        s.erase(next);
        current = *s.upper_bound(current);

        if (s.upper_bound(current) == s.end())
            current = 0;
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
