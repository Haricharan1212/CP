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
    int n, c;
    cin >> n >> c;

    string s;
    cin >> s;

    int l = 0;
    int curra = 0, currb = 0, rude = 0;

    int ans = 0;

    rep (r, 0, n){
        // cout << l << ' ' << r << ' ' << curra << ' ' << currb << ' ' << rude << '\n';

        if (s[r] == 'a') curra++;
        else currb++, rude += curra;

        while (rude > c){
            if (s[l] == 'a') curra--, rude -= currb;
            else currb--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << ' ';

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