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
        cout << "NO" << endl;
        return;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    rep(k, 2, 1e6 + 5)
    {
        int sum = 1 + k;
        int curr = k;

        while (true)
        {
            curr *= k;
            sum += curr;

            a.insert(sum);

            if (curr *)
        }
    }

    while (tc--)
        solve();

    return 0;
}
