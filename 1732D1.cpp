// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef unsigned long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

void solve()
{
    ll n;
    cin >> n;

    vector<pair<char, ll>> s(n);
    for (ll i = 0; i < n; i++)
        cin >> s[i].first >> s[i].second;

    map<ll, set<ll>> m;
    map<ll, ll> ans;
    set<ll> f;
    for (ll i = 0; i < n; i++)
    {
        if (s[i].first == '+')
        {
            f.insert(s[i].second);
            ll num = s[i].second;
            for (auto j : m[num])
            {
                m[j * (num / j + 1)].insert(j);
                ans[j] = j * (num / j + 1);
            }
            if (m[num].count(num) == 0)
            {
                ll j = 2;
                while (f.count(num * j))
                    j++;

                m[j * num].insert(num);
                ans[num] = j * num;
            }
            vi z;
            z.push_back(1e9 + 19);
            m[num] = ;
        }
        else
            cout << ((ans[s[i].second]) ? ans[s[i].second] : s[i].second) << endl;
        // for (auto i : m)
        // {
        //     cout << i.first << ' ';
        //     for (auto j : i.second)
        //         cout << j << ' ';
        //     cout << endl;
        // }
    }
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
