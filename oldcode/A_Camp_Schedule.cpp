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
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int onescount = count(s.begin(), s.end(), '1');
    int zeroscount = n - onescount;

    string ans = "";
    int reqones = count(t.begin(), t.end(), '1');
    int reqzeros = t.size() - reqones;

    while (onescount >= reqones && zeroscount >= reqzeros)
    {
        ans += t;
        onescount -= reqones;
        zeroscount -= reqzeros;
    }

    while (onescount--)
        ans += '1';
    while (zeroscount--)
        ans += '0';

    cout << ans << "\n";
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