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

    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << "2 1" << endl;
    }
    else
    {
        vi a(n, -1);
        a[0] = 2;
        a[n - 1] = 3;
        a[n / 2] = 1;
        int cnt = 4;
        rep(i, 0, n)
        {
            if (a[i] == -1)
                a[i] = cnt++;
        }

        rep(i, 0, n)
        {
            cout << a[i] << " ";
        }
        cout << endl;
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
