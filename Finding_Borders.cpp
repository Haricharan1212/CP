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

const int m = 1e9 + 7;

int p = 97;

int modexp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve()
{

    string s;
    cin >> s;

    int n = s.size();

    vi prefs(n);
    int curr = 0;

    rep(i, 0, n)
    {
        curr += ((s[i] - 'a') * modexp(p, i)) % m;
        prefs[i] = curr;
    }

    vi suffs(n);
    curr = 0;

    cout << endl;

    rep(i, 0, n)
    {
        curr = (curr * p + (s[n - 1 - i] - 'a')) % m;
        suffs[i] = curr;
    }

    rep(i, 0, n - 1)
    {
        if (prefs[i] == suffs[i])
            cout << i + 1 << " ";
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
