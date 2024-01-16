// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

void solve()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int ti;
    cin >> ti;

    si eq, blk, diff;

    rep(i, 0, n)
    {
        if (s[i] == t[i])
            eq.insert(i);
        if (s[i] != t[i])
            diff.insert(i);
    }

    int q;
    cin >> q;

    vi tims(q + 5, -1);

    rep(current, 0, q)
    {
        int x;
        cin >> x;

        // cout << "eq";
        // for (auto i : eq)
        //     cout << i << " ";
        // cout << "diff";
        // for (auto i : diff)
        //     cout << i << " ";
        // cout << "blk";
        // for (auto i : blk)
        //     cout << i << " ";
        // cout << endl;

        if (current >= ti && tims[current - ti] != -1)
        {
            blk.erase(tims[current - ti]);
            if (s[tims[current - ti]] == t[tims[current - ti]])
                eq.insert(tims[current - ti]);
            else
                diff.insert(tims[current - ti]);
            tims[current - ti] = -1;
        }

        if (x == 1)
        {
            int ind;
            cin >> ind;

            ind--;
            diff.erase(ind);
            blk.insert(ind);
            tims[current] = ind;
        }
        else if (x == 2)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            b--, d--;

            eq.erase(b);
            eq.erase(d);
            diff.erase(b);
            diff.erase(d);

            if (a == 1 && c == 1)
                swap(s[b], s[d]);
            else if (a == 1 && c == 2)
                swap(s[b], t[d]);
            else if (a == 2 && c == 1)
                swap(t[b], s[d]);
            else
                swap(t[b], t[d]);

            if (s[b] == t[b])
                eq.insert(b);
            else
                diff.insert(b);

            if (s[d] == t[d])
                eq.insert(d);
            else
                diff.insert(d);
        }

        else
        {
            if (diff.size() == 0)
            {
                cout << "YES" << endl;
                continue;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
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
