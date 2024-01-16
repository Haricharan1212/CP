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
    string s = "ppzfsncqyzmuwrcv";
    int n = s.size();
    int k = 8;

    int arr[26] = {0};
    set<char> f;

    rep(i, 0, n)
    {
        arr[s[i] - 'a']++;
        f.insert(s[i]);
    }

    vi chars;

    // three 2s, ten 1s

    // 2 * 2 * 2 * 10C4 =

    rep(i, 0, 26)
    {
        if (arr[i])
            cout << arr[i] << " ";
    }

    for (auto i : f)
    {
        chars.push_back(i);
    }
    int ans = 0;
    rep(i, 0, chars.size())
    {
        f.erase(chars[i]);
        rep(j, i + 1, chars.size())
        {
            f.erase(chars[j]);
            int curr = 1;

            rep(k, 0, 26)
            {
                if (f.find(k + 'a') != f.end())
                    curr *= arr[k];
            }
            ans += curr;

            f.insert(chars[i]);
        }
        f.insert(chars[i]);
    }

    cout << ans << endl;

    // for (int i = 0; i <= n; i++)
    //     cout << fixed << setprecision(30) << a[i] << " ";
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
