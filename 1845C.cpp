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
    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.size();

    string l, r;
    cin >> l >> r;

    int ind = 0;
    int i;
    int flag = 1;

    set<int> current;

    for (int i = l[0]; i <= r[0]; i++)
        current.insert(i);

    for (i = 0; i < n; i++)
    {
        if (current.count(s[i]))
        {
            current.erase(s[i]);
        }
        if (current.size() == 0)
        {
            ind++;
            for (int j = l[ind]; j <= r[ind]; j++)
                current.insert(j);
        }

        if (ind == m)
            break;
    }

    if (i == n)
    {
        flag = 0;
    }

    if (flag == 0)
    {
        cout << "YES" << endl;
        return;
    }
    else
        cout << "NO" << endl;
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
