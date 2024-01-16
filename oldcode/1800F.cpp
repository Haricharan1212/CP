// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

struct Comparer
{
    bool operator()(const bitset<26> &b1, const bitset<26> &b2) const
    {
        return b1.to_ulong() < b2.to_ulong();
    }
};

void solve()
{
    int n;
    cin >> n;

    map<bitset<26>, int, Comparer> m[26];

    rep(f, 0, n)
    {
        bitset<26> an(0);
        string s;
        cin >> s;
        set<int> ss;
        for (auto i : s)
        {
            an[i - 'a'] = ~(an[i - 'a']);
            ss.insert(i - 'a');
        }
        for (int i = 0; i < 26; i++)
            if (ss.count(i) == 0)
                m[i][an]++;
    }

    int ans = 0;
    bitset<26> ann;

    for (int k = 0; k < 26; k++)
        for (auto i : m[k])
        {
            ann = ~i.first;
            ann.flip(k);

            if (m[k].count(ann))
                ans += i.second * m[k][ann];
        }
    cout << ans / 2 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
