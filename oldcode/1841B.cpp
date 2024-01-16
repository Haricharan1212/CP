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
    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    string s = "1";
    vi c = {a[0]};

    int ind = -1;

    rep(i, 1, n)
    {
        if (c[c.size() - 1] <= a[i])
        {
            c.push_back(a[i]);
            s.push_back('1');
        }
        else if (a[i] <= a[0])
        {
            ind = i;
            c.push_back(a[i]);
            s.push_back('1');
            break;
        }
        else
            s.push_back('0');
    }

    if (ind != -1)
        rep(i, ind + 1, n)
        {
            if (c[c.size() - 1] <= a[i] && a[i] <= a[0])
            {
                c.push_back(a[i]);
                s.push_back('1');
            }
            else
                s.push_back('0');
        }

    cout << s << endl;
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
