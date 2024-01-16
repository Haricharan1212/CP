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

int f(char c)
{
    if (c == 'A')
        return 1;
    else if (c == 'B')
        return 10;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 1000;
    else if (c == 'E')
        return 10000;
    else
        return -1;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    int freq[5] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'A']++;
    }

    int current = 0;
    int mx = -1e18;
    int cmax = 0;

    vi pref(n + 1, 0);

    int ccmax = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        pref[i] = pref[i + 1];
        int num = s[i] - 'A';
        if (num < ccmax)
            pref[i] -= f(s[i]);
        else
            pref[i] += f(s[i]);
        ccmax = max(ccmax, num);
    }

    vii a(5);
    for (int i = 0; i < n; i++)
    {
        a[s[i] - 'A'].push_back(-i);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            int anss = 0;

            if (j < cmax)
                anss -= f('A' + j);
            else
                anss += f('A' + j);
            cout << anss + current << endl;
            mx = max(mx, anss + current);
        }

        int num = (s[i] - 'A');

        if (num < cmax)
            current -= f(s[i]);
        else
            current += f(s[i]);
        cmax = max(cmax, num);
        // cout << current << ' ' << cmax << ' ';
    }

    int mx = -1e18;
    vii dp(n + 1, vi(5, 0));

    int cc = 'A';

    cout << mx << endl;
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
