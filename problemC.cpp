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
    int n, q;
    cin >> n >> q;

    vi a(n + 1);
    map<int, vi> m, mm;
    vi pref(n + 1, 0);
    mm[0] = {0};
    vi ss(n + 1, 0);
    rep(i, 1, n + 1)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
        ss[i] = ss[i - 1] + a[i];

        if (i % 2)
            m[pref[i]].push_back(i);
        else
            mm[pref[i]].push_back(i);
    }

    // for (auto i : m)
    // {
    //     cout << i.first << ": ";
    //     for (auto j : i.second)
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    // for (auto i : mm)
    // {
    //     cout << i.first << ": ";
    //     for (auto j : i.second)
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int op = 0;

        if ((r - l + 1) % 2 == 1)
        {
            if (pref[r] == pref[l - 1])
                op = 1;
            else
                op = -1;
        }
        else
        {
            if (pref[r] == pref[l - 1])
            {
                if (r % 2)
                    if (lower_bound(mm[pref[r]].begin(), mm[pref[r]].end(), l - 1) != mm[pref[r]].end() && *lower_bound(mm[pref[r]].begin(), mm[pref[r]].end(), l - 1) < r)
                        op = 2;
                    else
                        op = -1;
                else
                {
                    if (lower_bound(m[pref[r]].begin(), m[pref[r]].end(), l - 1) != m[pref[r]].end() && *lower_bound(m[pref[r]].begin(), m[pref[r]].end(), l - 1) < r)
                        op = 2;
                    else
                        op = -1;
                }
                        }
            else
            {
                op = -1;
            }
        }

        if (ss[r] == ss[l - 1])
            op = 0;

        cout << op << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
