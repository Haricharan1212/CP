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

// 10 10 1 3 4 1
// * * A *
// * * * *
// * * * *
// B * * *

void solve()
{
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;

    int diff = (xb - xa);
    int ydiff = abs(yb - ya);

    if (diff <= 0)
    {
        cout << "Draw" << endl;
        return;
    }
    else
    {
    int escp = diff/2;

        if (diff % 2)
        {
            if (ydiff <= 1)
            {
                cout << "Alice" << endl;
                return;
            }

        }
        else
        {
            if (ydiff == 0)
            {
                cout << "Bob" << endl;
                return;
                }
        }
    }

    cout << "Draw" << endl;
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