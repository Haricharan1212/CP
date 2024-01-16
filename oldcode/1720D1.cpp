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

int lis(vi arr, int n)
{
    vector<int> b;
    set<int> s;

    // setting iterator for set
    set<int>::iterator it;

    // storing unique elements
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    // creating sorted vector
    for (it = s.begin(); it != s.end(); it++)
    {
        b.push_back(*it);
    }
    int m = b.size(), i, j;
    int dp[m + 1][n + 1];

    // storing -1 in dp multidimensional array
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    // Finding Longest common Subsequence of the two
    // arrays
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[j - 1] == b[i - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        a[i] ^= i;

    cout << lis(a, n) << endl;
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
