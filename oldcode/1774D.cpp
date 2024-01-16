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
    int n, m;
    cin >> n >> m;

    bool arr[n][m];
    map<int, int> mp;

    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        int one = 0;
        for (int j = 0; j < m; j++)
            cin >> arr[i][j], ones += arr[i][j], one += arr[i][j];

        mp[i] = one;
    }
    if (ones % n != 0)
    {
        cout << -1 << endl;
        return;
    }
    int num = ones / n;

    vector<vector<int>> a;
    for (int j = 0; j < m; j++)
    {
        vector<int> inda, indb;

        for (int i = 0; i < n; i++)
        {
            if ((mp[i] > num) && (arr[i][j] == 1))
                inda.push_back(i);
            if ((mp[i] < num) && (arr[i][j] == 0))
                indb.push_back(i);
        }
        for (int i = 0; i < min(inda.size(), indb.size()); i++)
        {
            a.push_back({inda[i], indb[i], j});
            mp[inda[i]]--;
            mp[indb[i]]++;
        }
    }

    cout << a.size() << endl;
    for (auto i : a)
        cout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] + 1 << endl;
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
