// Haricharan

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

void solve()
{
    int n;
    cin >> n;

    if (n == 2)
    {
        cout << "! 1 2 2 1" << endl;
        cout.flush();
        int x;
        cin >> x;

        return;
    }

    cout << "+ " << n + 1 << endl;
    cout.flush();
    int x;
    cin >> x;

    cout << "+ " << n + 2 << endl;
    cout.flush();

    cin >> x;

    // n = 1 - 6, 2 - 5, 3 - 4, 2 - 6, 3 - 5    1 - 6 - 2 - 5 - 3 - 4
    // 1 - 7, 2 - 6, 3 - 5, 2 - 7, 3 - 6, 4 - 5 .... 1 - 7 - 2 - 6 - 3 - 5 - 4

    vector<pair<int, int>> v;

    rep(i, 2, n + 1)
    {
        cout << "? 1 " << i << endl;
        cout.flush();

        int x;
        cin >> x;

        v.push_back({x, i});
    }
    sort(v.begin(), v.end(), greater<pi>());

    int a = v[0].second;

    vector<pair<int, int>> vv;
    vv.push_back({0, a});
    vv.push_back({v[0].second, 1});

    rep(i, 2, n + 1)
    {
        if (i == a)
            continue;
        cout << "? " << a << " " << i << endl;
        cout.flush();
        int x;
        cin >> x;

        vv.push_back({x, i});
    }

    sort(vv.begin(), vv.end(), greater<pi>());

    vi per(n);
    int count = 0;

    for (int i = 0; i < n; i += 2)
    {
        per[i] = count++;
    }
    for (int i = n - 1; i >= 0; i -= 2)
    {
        per[i] = count++;
    }

    vi perm(n);
    rep(i, 0, n) { perm[per[i]] = i; }

    vector<pi> vvv;
    rep(i, 0, n)
    {
        vvv.push_back({perm[i], vv[i].second});
    }
    sort(vvv.begin(), vvv.end());

    cout << "! ";

    rep(i, 0, n)
    {
        cout << vvv[i].second << " ";
    }
    reverse(vvv.begin(), vvv.end());
    rep(i, 0, n)
    {
        cout << vvv[i].second << " ";
    }

    cout << endl;
    cout.flush();

    cin >> x;
}

int32_t main()
{
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
