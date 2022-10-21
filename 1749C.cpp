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

    multiset<int> b;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        b.insert(a);
    }

    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
        multiset<int> s = b;
        int flag = 1;
        for (int i = 1; i <= k; i++)
        {
            auto pt = s.lower_bound(k - i + 1);
            if (*s.begin() == *s.rbegin() && *s.begin() > k - i + 1)
            {
                flag = 0;
                break;
            }
            if (pt == s.end())
                pt--;
            if (pt == s.begin() && *pt > k - i + 1)
            {
                flag = 0;
                break;
            }
            else
            {
                if (*pt != k - i + 1)
                    pt--;

                s.erase(pt);

                auto b = s.upper_bound(k - i);
                if (b == s.begin())
                    continue;
                else
                {
                    b--;
                    int num = *b;
                    s.erase(b);

                    s.insert(num + k - i + 1);
                }
            }
        }
        if (flag)
            ans = max(ans, k);
        else
            break;
    }

    cout << ans << endl;
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
