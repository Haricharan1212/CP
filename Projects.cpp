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

struct s
{
    int a, b, p;
};

void solve()
{
    int n;
    cin >> n;
    vector<s> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i].a >> vec[i].b >> vec[i].p;

    map<int, int> compress;
    int count = 0;
    for (int i = 0; i < n; i++)
        compress[vec[i].b] = count++;

    vi dp(n + 1, 0);
    vector<vector<pair<int, int>>> f(n);
    for (int i = 0; i < n; i++)
    {
        f[compress[vec[i].b]].push_back(make_pair(vec[i].a, vec[i].p));
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : f[i])
        {
            dp[i] = max(dp[i - j.first] + [], dp[i])
        }
    }
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //   cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
