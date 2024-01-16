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

    set <int> s;
    rep (i, 1, n + 1)
        s.insert(i);

    rep (i, 0, n){
        int x;
        cin >> x;

        auto it = s.lower_bound(x);
        it = it == s.end()? s.begin(): it;
        cout << *it << " ";
        s.erase(it);
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