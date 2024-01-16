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

bool check(string a)
{
    string b = "abc";

    for (int i = 0; i < 3; i++)
        if (a[i] == b[i] || a[i] == '?' || b[i] == '?')
            continue;
        else
            return false;

    return true;
}

const int mod = 1e9 + 7;

int modexp (int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ques = count(s.begin(), s.end(), '?');
    int currq = 0;
    int ans = 0;
    cout << ans << '\n';

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