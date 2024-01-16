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
    int n, m;
    cin >> n >> m;

    vii perms(n);
    map<vi, int> mp;

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            int x;
            cin >> x;
            perms[i].push_back(--x);
            mp[perms[i]]++;
        }
    }

    rep(i, 0, n)
    {
        vi inverse_perm(m);
        rep(j, 0, m)
        {
            inverse_perm[perms[i][j]] = j;
        }

        for (int i = m - 1; i >= 0; i--)
        {
            if (mp[inverse_perm] > 0)
            {
                cout << i + 1 << ' ';
                break;
            }
            else
                inverse_perm.pop_back();

            if (inverse_perm.size() == 0)
            {
                cout << 0 << ' ';
            }
        }
    }

    cout << endl;
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
