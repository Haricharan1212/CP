#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define int long long int

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

void solve()
{

    int l, r;
    cin >> l >> r;

    set<int> ans;

    if (l <= 100 && r <= 100)
    {
        rep(i, l, r + 1) rep(j, l, r + 1) if ((i ^ j) == i + j) ans.insert(i ^ j);
        cout << ans.size() << endl;
    }
    else if (l == 0)
    {
        cout << (int)powl(2, ceill(log2l(r))) << endl;
    }
    else
        cout << 0 << endl;
}
int32_t main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}