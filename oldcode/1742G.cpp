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
    ll n;
    cin >> n;

    multiset<ll> s;
    for (ll i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }

    vector<ll> b(1);
    b[0] = *--s.end();
    s.erase(--s.end());

    for (int i = 1; i < min(33ll, n); i++)
    {
        ll orr = 0;
        for (ll j = 0; j < i; j++)
            orr = orr | b[j];
        ll mx = -1, num = 0;
        for (auto j : s)
        {
            if ((orr | j) > mx)
            {
                mx = orr | j;
                num = j;
            }
        }
        b.push_back(num);
        s.erase(s.find(num));
    }
    for (auto i : b)
        cout << i << ' ';
    for (auto i : s)
        cout << i << ' ';
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
