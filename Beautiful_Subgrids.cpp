// Haricharan
#include <bits/stdc++.h>

#pragma GCC target("popcnt")

using namespace std;
 
#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

const int mx = 3005;

void solve()
{
    int n;
    cin >> n;
 
    vector<bitset <mx>> v(n);
 
    rep(i, 0, n)
    {
        string s;
        cin >> s;
        v[i] = bitset<mx>(s);
    }
 
    int ans = 0;
 
    rep(i, 0, n) rep(j, 0, i)
    {
        int num = (v[i] & v[j]).count();
        ans += ((num) * (num - 1)) / 2;
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