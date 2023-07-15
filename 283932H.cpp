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
    string ss;
    cin >> ss;

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    int b = count(ss.begin(), ss.end(), 'B');
    int s = count(ss.begin(), ss.end(), 'S');
    int c = count(ss.begin(), ss.end(), 'C');

    int r;
    cin >> r;

    int l = 0, h = 1e13;

    while (l < h)
    {
        int m = (l + h + 1) / 2;

        int req = max(0LL, m * b - nb) * pb + max(0LL, m * s - ns) * ps + max(0LL, m * c - nc) * pc;

        if (req <= r)
            l = m;
        else
            h = m - 1;
    }

    cout << l;
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
