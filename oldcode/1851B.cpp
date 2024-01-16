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
    vector<int> a(n), b, c;
    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] % 2) // odd
            b.push_back(a[i]);
        else // even
            c.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<int> ans;
    int num;

    int j = 0, k = 0;
    rep(i, 0, n)
    {
        if (a[i] % 2)
        {
            num = b[j++];
        }
        else
        {
            num = c[k++];
        }
        ans.push_back(num);
    }

    sort(a.begin(), a.end());

    rep(i, 0, n)
    {
        if (a[i] != ans[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
