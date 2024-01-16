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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

struct S
{
    int a, b, p;
};

void solve()
{
    int n;
    cin >> n;

    map<int, int> m;
    vector<S> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].p;
        a[i].b++;
        m[a[i].a];
        m[a[i].b];
    }

    int count = 1;

    for (auto i : m)
        m[i.first] = count++;

    vector<vector<S>> z(m.size() + 1);

    for (int i = 0; i < n; i++)
    {
        z[m[a[i].b]].push_back(a[i]);
    }

    vector<ll> dp(m.size() + 1);
    dp[0] = 0;

    // for (auto i : z)
    // {
    //     for (auto j : i)
    //         cout << j.a << j.b << j.p << endl;
    //     cout << endl;
    // }

    for (int i = 1; i <= m.size(); i++)
    {
        dp[i] = dp[i - 1];
        if (z[i].size() != 0)
            for (auto j : z[i])
                if (i >= m[j.a])
                    dp[i] = max(dp[i], dp[m[j.a]] + j.p);
    }

    // for (auto i : dp)
    //     cout << i << ' ';

    cout << dp[m.size()];
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
