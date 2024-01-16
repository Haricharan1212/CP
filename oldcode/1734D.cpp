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
    int n, k;
    cin >> n >> k;

    vi a(n);
    vi plus;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            plus.push_back(i);
    }

    deque<pair<int, int>> lefts;
    deque<pair<int, int>> rights;
    for (int i = 0; i < plus.size() - 1; i++)
    {
        if (plus[i] < k)
        {
            int sum = 0;
            for (int j = plus[i] + 1; j < plus[i + 1]; j++)
                sum += a[j];
            lefts.push_back(make_pair(a[plus[i]] + sum, sum));
        }
        else
        {
            int sum = 0;
            for (int j = plus[i] + 1; j < plus[i + 1]; j++)
                sum += a[j];
            rights.push_back(make_pair(a[plus[i]] + sum, sum));
        }
    }
    reverse(rights.begin(), rights.end());

    k--;
    int current = a[k];
    for (int i = 0; i < plus.size() + 5; i++)
    {
        if (lefts[0].second >= current && lefts[0].first >= 0)
        {
            current += lefts[0].first;
            lefts.pop_front();
            continue;
        }
        if (rights[0].second >= current && rights[0].first >= 0)
        {
            current += rights[0].first;
            rights.pop_front();
            continue;
        }
        if (lefts.empty() || rights.empty())
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
