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

    int k;
    cin >> k;
    int n = 1 << k;

    vi factorial(n + 2);

    factorial[0] = 1;
    rep(i, 1, n + 2)
    {
        factorial[i] = (factorial[i - 1] * i);
    }

    vi a(n + 1);
    rep(i, 1, n + 1)
    {
        cin >> a[i];
        a[i]--;
    }

    int ans = 1;

    int curr = 3;

    for (int i = 1; i < k; i++)
    {
        vi curs;
        int pow = 1 << i;

        for (int i = 0; i < pow; i++)
        {
            curs.push_back(curr++);
        }

        map<int, int> m;

        for (auto i : curs)
            if (a[i] != -1)
                m[a[i] / (n / pow)]++;
            else
                m[a[i]]++;

        for (auto i : curs)
            cout << i << ' ';

        int posses = m[-1];
        for (auto i : m)
        {
            if (i.first == -1)
                continue;
            if (i.second >= 2)
            {
                cout << 0 << endl;
                return;
            }
        }

        cout << endl;

        ans *= factorial[posses];
    }

    cout << ans << endl;
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
