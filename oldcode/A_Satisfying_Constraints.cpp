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

    vi eqs;

    int low = 0;
    int high = 1e9;

    rep(i, 0, n)
    {
        int a, b;
        cin >> b >> a;
        if (b == 1)
        {
            low = max(low, a);
        }
        else if (b == 2)
        {
            high = min(high, a);
        }
        else{
            eqs.push_back(a);}

    }

    int ans = max(0LL, high - low + 1);

    for (auto i: eqs){
        if (i >= low && i <= high){
            ans--;
        }
    }

    cout << max (0LL, ans) << endl;

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