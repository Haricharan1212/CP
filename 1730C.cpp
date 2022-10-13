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
    string s;
    cin >> s;
    int n = s.size();

    int arr[10] = {0};

    for (int i = 0; i < n; i++)
        arr[s[i] - '0']++;

    int current[10] = {0};

    multiset<char> f;

    for (int i = 0; i < n; i++)
    {
        current[s[i] - '0']++;

        if (s[i] == '0' || s[i] == '9')
        {
            f.insert(s[i]);
            continue;
        }
        else
        {
            int flag = 0;
            for (char j = '0'; j < s[i]; j++)
            {
                if (current[j - '0'] == arr[j - '0'])
                    continue;
                else
                {
                    f.insert(++s[i]);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                f.insert(s[i]);
        }
    }
    for (auto i : f)
        cout << i;
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
