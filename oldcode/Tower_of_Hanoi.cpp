// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

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

vector<pi> hanoi(int start, int end, int n)
{

    if (n == 1)
    {
        return {{start, end}};
    }
    else if (n == 2)
    {
        return {{start, 6 - start - end}, {start, end}, {6 - start - end, end}};
    }
    else
    {
        vector<pi> ans;
        vector<pi> temp = hanoi(start, 6 - start - end, n - 1);
        for (auto x : temp)
        {
            ans.push_back(x);
        }
        ans.push_back({start, end});
        temp = hanoi(6 - start - end, end, n - 1);
        for (auto x : temp)
        {
            ans.push_back(x);
        }
        return ans;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> ans = hanoi(1, 3, n);
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
