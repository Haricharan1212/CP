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

    deque<int> a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    sort(
        a.begin(), a.end(), [](int a, int b)
        { return abs(a) < abs(b); });

    vi ans;
    while (a.size())
    {
        ans.push_back(a[0]);
        a.pop_front();
        if (a.size())
        {
            ans.push_back(a.back());
            a.pop_back();
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i << " ";

    cout << endl;
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
