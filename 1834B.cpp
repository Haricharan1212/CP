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

    string l, r;
    cin >> l >> r;

    int ans = 0;

    int ind = l.size() + 1;

    if (l.size() == r.size())
    {
        for (int i = 0; i < r.size(); i++)
            if (l[i] != r[i])
            {
                ind = i;
                break;
            }
        if (ind != l.size() + 1)
            ans += r[ind] - l[ind];
        for (int i = ind + 1; i < r.size(); i++)
        {
            ans += 9;
        }
        cout << ans << endl;
        return;
    }

    ind = r.size();
    ans = 0;

    for (int i = 0; i < r.size() - 1; i++)
    {
        ans += 9;
    }

    ans += r[0] - '0';
    cout << ans << endl;
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
