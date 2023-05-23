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

void solve()
{
    int l, r;
    cin >> l >> r;

    int arr[19][2];

    rep(i, 0, 19)
    {
        arr[i][0] = l % 10;
        l /= 10;
        arr[i][1] = r % 10;
        r /= 10;
    }

    vi ans;
    int flag = 0;

    for (int i = 18; i >= 0; i--)
    {
        if (arr[i][0] == arr[i][1] && !flag)
            ans.push_back(arr[i][0]);
        else if (flag)
            ans.push_back(ans.size() - 2);
        else
        {
            if (arr[i][1] - arr[i][0] >= 2)
            {
                ans.push_back(arr[i][0] + 1);
                flag = 1;
            }
            else{
                

            }

        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
