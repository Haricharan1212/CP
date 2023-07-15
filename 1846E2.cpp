// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

si a;

void solve()
{
    int n;
    cin >> n;

    if (a.count(n))
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        float num = (-1 + sqrtl(1 - 4 * (1 - n))) / 2.0;
        int b = llround(num);
        if ((1 + b + b * b == n) && b > 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int mx = 1e18;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    rep(k, 2, 1e6)
    {
        int sum = 1 + k;
        int curr = k;

        while (true)
        {
            curr *= k;
            sum += curr;
            a.insert(sum);

            if (sum > 1e18 / k)
                break;
        }
    }

    while (tc--)
        solve();

    return 0;
}
