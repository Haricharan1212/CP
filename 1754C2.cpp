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
    vi a(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1 || a[i] == -1)
            count++;
    }
    if (count % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    int current = 0;
    int ind = 0;
    deque<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        current += a[i];
        if (current == 1 || current == -1)
        {
            if (a[i] == -1 || a[i] == 1)
                ind = i;
        }
        else
        {
            if (current == 0)
            {
                if (a[i] != 0)
                {
                    if ((ind - i) % 2 == -1)
                    {
                        ans.push_back(make_pair(ind, i - 1));
                        ans.push_back(make_pair(i, i));
                    }
                    else
                    {
                        ans.push_back(make_pair(ind, i));
                    }
                }
                else
                {
                    ans.push_back(make_pair(i, i));
                }
            }
            else
            {
                current = 0;
                if ((ind - i) % 2 == 0)
                {
                    ans.push_back(make_pair(ind, i - 2));
                    ans.push_back(make_pair(i - 1, i));
                }
                else
                {
                    ans.push_back(make_pair(ind, i));
                }
            }
        }
    }
    if (ans.size() == 0)
    {
        cout << "1 " << n << endl;
        return;
    }

    if (ans[0].first != 0)
        ans.push_front(make_pair(0, ans[0].first - 1));

    if (ans[ans.size() - 1].second != n - 1)
    {
        ans.push_back(make_pair(ans[0].second + 1, n - 1));
    }

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << endl;
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
