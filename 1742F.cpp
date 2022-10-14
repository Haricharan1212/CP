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
    ll q;
    cin >> q;
    ll s[26] = {0};
    ll t[26] = {0};
    s[0]++, t[0]++;
    int a = 1, b = 1;
    for (int j = 0; j < q; j++)
    {
        int type, k;
        string f;
        cin >> type >> k >> f;
        if (type == 1)
        {
            for (auto i : f)
                s[i - 'a'] += k;
            a += k * f.size();
        }
        else
        {
            for (auto i : f)
                t[i - 'a'] += k;
            b += k * f.size();
        }

        int last = 0;
        for (int i = 25; i >= 0; i--)
        {
            if (s[i] != 0)
            {
                last = i;
                break;
            }
        }
        int last2 = 0;
        for (int i = 25; i >= 0; i--)
        {
            if (t[i] != 0)
            {
                last2 = i;
                break;
            }
        }
        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (i != last || i != last2)
            {
                if (s[i] > t[i])
                {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
                else if (s[i] < t[i])
                {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
                else
                    continue;
            }
            else
            {
                if (a < b)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
            }
        }
    }
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
