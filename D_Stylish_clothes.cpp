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

vi inp()
{

    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end());
    return a;
}

const int mx = 1e5 + 5;

void solve()
{
    vi a = inp(), b = inp(), c = inp(), d = inp();

    vii fin = {a, b, c, d};

    int anss = 1e9;
    vi finanss;

    rep(i, 1, mx + 1)
    {
        vi ans;
        int flag = 1;

        rep(j, 0, 4)
        {
            auto pt = lower_bound(fin[j].begin(), fin[j].end(), i);
            if (pt == fin[j].end())
            {
                flag = 0;
                break;
            }

            ans.push_back(*pt);
        }

        if (flag)
        {
            int temp = *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end());

            if (temp < anss)
            {
                anss = min(anss, temp);
                finanss = ans;
            }
        }
    }

    for (auto i: finanss) cout << i << ' ';

}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}