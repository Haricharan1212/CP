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

set<int> countSetBits(int n)
{
    set<int> a;
    int num = 0;
    while (n)
    {
        if (n & 1)
        {
            a.insert(num);
        }
        num++;
        n >>= 1;
    }
    return a;
}

void solve()
{

    multiset<int> s = {3, 4, 5, 6};

    int n = s.size();
    int tot = 0;
    for (int i = 0; i < n - 1; i++)
    {

        auto a = s.begin();
        auto b = ++s.begin();
        int ans = *a + *b;
        tot += ans;
        s.erase(a);
        s.erase(b);
        s.insert(ans);
    }

    for (auto i : s)
        cout << i << endl;
    cout << tot;
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
