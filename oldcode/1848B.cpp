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

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int fib(int n)
{
    int fib[n + 2];

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    map<int, vi> m;

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        m[x].push_back(i + 1);
    }

    int ans = n;

    for (auto i : m)
    {
        multiset<int> maxdiffs;
        for (int j = 0; j < (long long)i.second.size() - 1; j++)
        {
            maxdiffs.insert(i.second[j + 1] - i.second[j] - 1);
        }
        maxdiffs.insert(i.second[0] - 1);
        maxdiffs.insert(n + 1 - i.second[i.second.size() - 1] - 1);

        // for (auto j : maxdiffs)
        // {
        //     cout << j << ' ';
        // }

        int x = *maxdiffs.rbegin();

        maxdiffs.erase(maxdiffs.find(x));
        maxdiffs.insert((x) / 2);
        int num = *maxdiffs.rbegin();

        // cout << num << 'x';

        ans = min(ans, num);
    }

    cout << ans << "\n";
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
