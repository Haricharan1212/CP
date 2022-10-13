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
    string s;
    cin >> s;

    int n = s.size();
    vector<int> v[26];

    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a'].push_back(i);
    }
    int start = s[0] - 'a';
    int end = s[n - 1] - 'a';

    int cost = abs(start - end);
    int jumps = 0;
    vi ans;
    if (start < end)
    {
        for (int i = start; i <= end; i++)
        {
            for (auto j : v[i])
                ans.push_back(j);
            jumps += v[i].size();
        }
    }
    else
    {
        for (int i = start; i >= end; i--)
        {
            for (auto j : v[i])
                ans.push_back(j);
            jumps += v[i].size();
        }
    }
    cout << cost << ' ' << jumps << endl;
    for (auto i : ans)
        cout << i + 1 << ' ';
    cout << endl;
}

int main()
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
