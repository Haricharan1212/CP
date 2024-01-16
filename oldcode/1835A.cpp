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

    int A, B, C, k;
    cin >> A >> B >> C >> k;

    int aa = pow(10, A - 1);
    int bb = pow(10, B - 1);
    int cc = pow(10, C - 1);
    int aaa = 10 * aa - 1;
    int bbb = 10 * bb - 1;
    int ccc = 10 * cc - 1;

    if (C < (max(A, B)) || max(A, B) + 1 < C)
    {
        cout << -1 << endl;
        return;
    }

    rep(i, aa, aaa + 1)
    {
        int bmin = max(bb, cc - i);
        int bmax = min(bbb, ccc - i);

        if (bmin > bmax)
            continue;

        int f = bmax - bmin + 1;

        if (k <= f)
        {
            int b = bmin + k - 1;
            int c = i + b;
            cout << i << " + " << b << " = " << c << endl;
            return;
        }
        else if (k > f)
        {
            k -= f;
        }
    }

    cout << -1 << endl;
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
