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

// every 01 -> 10

// 10110

// 011
// 101

// 0111
// 1011

// 10110
// 01101
// 01110
// invalid: 10101
// invalid: 10110

// maintain graph of index, index'

// 

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    vi indices;

    rep (i, 0, n){
        if (s[i] == '0' && s[(i + 1) % n] == '1'){
            indices.push_back(i);
        }
    }

    int ans = 0;


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