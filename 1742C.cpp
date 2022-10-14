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

    char arr[8][8];

    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 8; j++)
            arr[i][j] = s[j];
    }

    for (int i = 0; i < 8; i++)
    {
        int flag = 1;
        for (int j = 0; j < 7; j++)
            if (arr[i][j] == arr[i][j + 1] && arr[i][j] == 'R')
                continue;
            else
            {
                flag = 0;
                break;
            }
        if (flag)
        {
            cout << 'R' << endl;
            return;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        int flag = 1;
        for (int j = 0; j < 7; j++)
            if (arr[j][i] == arr[j + 1][i] && arr[j][i] == 'B')
                continue;
            else
            {
                flag = 0;
                break;
            }
        if (flag)
        {
            cout << 'B' << endl;
            return;
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
