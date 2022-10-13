// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

void solve()
{
    int n;
    cin >> n;

    int cnt[(int)1e6 + 1] = {0};
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        set<int> curr;
        for (int j = 1; j * j <= a; j++)
            if (a % j == 0)
                curr.insert(j), curr.insert(a / j);

        for (auto it = curr.rbegin(); it != curr.rend(); it++)
        {
            cnt[*it] += cnt[*it - 1], cnt[*it] %= ((int)1e9 + 7);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += cnt[i], ans = ans % ((int)1e9 + 7);
    cout << ans % ((int)1e9 + 7) << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
