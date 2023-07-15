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

int quad(int a, int b)
{
    if (a > 0 && b > 0)
        return 1;
    else if (a <= 0 && b >= 0)
        return 2;
    else if (a < 0 && b < 0)
        return 3;
    else
        return 4;
}

void solve()
{
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    xb -= xa, xc -= xa;
    yb -= ya, yc -= ya;

    int a = quad(xb, yb);
    int b = quad(xc, yc);

    if ((a == 1 && b == 3) || (a == 3 && b == 1) || (a == 2 && b == 4) || (a == 4 && b == 2))
    {
        cout << 1 << endl;
    }
    else if (a == b)
    {
        cout << min(abs(xc), abs(xb)) + min(abs(yc), abs(yb)) + 1 << endl;
    }
    else if (xc * xb >= 0 && yb * yc <= 0)
    {
        cout << min(abs(xb), abs(xc)) + 1 << endl;
    }
    else if (yc * yb >= 0 && xb * xc <= 0)
    {
        cout << min(abs(yc), abs(yb)) + 1 << endl;
    }
    else
    {
        cout << 'a' << endl;
    }
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
