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

int mod = 1e9 + 7;

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    int n = 1e6;
    vector<pair<ll, ll>> v(n + 1);
    v[0] = make_pair(0, 0);
    v[1] = make_pair(1, 1);

    for (int i = 2; i <= n; i++)
    {
        v[i].first = (v[i - 1].second + v[i - 1].first * 4) % mod;
        v[i].second = (v[i - 1].first + 2 * v[i - 1].second) % mod;
    }

    while (tc--)
    {
        int a;
        cin >> a;
        cout << (v[a].first + v[a].second) % mod << endl;
    }

    return 0;
}
