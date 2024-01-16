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

void solve()
{
    int n;
    cin >> n;

    int arr[12][12] = {0};

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        string s;
        cin >> s;
        int f = s.size();
        for (int i = 0; i < f - 1; i++)
        {
            arr[min(s[i], s[i + 1]) - 'a'][max(s[i], s[i + 1]) - 'a'] += a;
        }
    }
    map<int, pair<int, int>> m;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
            m[arr[i][j]] = make_pair(i, j);
    }

    vector<pair<int, int>> d(12);
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
