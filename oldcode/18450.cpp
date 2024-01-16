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

    int n, x, k;
    cin >> n >> k >> x;

    if (k == 1)
    {
        cout << "NO" << endl;
        return;
    }

    if (x == 1)
    {
        if (n % 2 == 0 && k == 2)
        {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            for (int i = 0; i < n / 2; i++)
            {
                cout << 2 << ' ';
            }
            cout << endl;
        }
        else if (n % 2 == 1 && k == 2)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            if (n % 2 == 0)
            {
                cout << 2 << ' ';
            }
            else
                cout << 3 << ' ';
            for (int i = 0; i < n / 2 - 1; i++)
            {
                cout << 2 << ' ';
            }
            cout << endl;
        }
    }
    else
    {
        cout << "YES" << endl;
        cout << n << endl;

        for (int i = 0; i < n; i++)
            cout << 1 << ' ';
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
