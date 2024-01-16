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

    string s;
    cin >> s;

    set<char> left, right;
    map<char, pair<char, char>> m;

    int count = 0;
    set<char> x;

    for (auto i : s)
    {
        x.insert(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (m[s[i]].second == 0)
        {

            for (char c = 'a'; c <= 'z'; c++)
            {
                if (m[c].first == 0 && c != s[i])
                {
                    char z = m[s[i]].first;
                    int flag = 0;
                    while (z != 0)
                    {

                        if (z == c)
                        {
                            flag = 1;
                            break;
                        }
                        z = m[z].first;
                    }
                    if (flag == 0)
                    {
                        m[s[i]].second = c;
                        m[c].first = s[i];
                        right.insert(c);
                        left.insert(s[i]);
                        break;
                    }
                }
            }
        }
    }
    {
        char f, b;
        for (auto i : m)
        {
            if (i.second.second == 0)
                f = i.first;
            if (i.second.first == 0)
                b = i.first;
        }
        m[f].second = b;
    }
    for (auto i : s)
        cout << m[i].second;
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
