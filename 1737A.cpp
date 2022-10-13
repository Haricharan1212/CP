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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<int>());

    int arr[26] = {0};
    for (int i = 0; i < n; i++)
    {
        arr[s[i] - 'a']++;
    }

    string ans = "";
    for (int i = 0; i < k; i++)
    {
        if (arr[0] == 0)
            break;
        for (int i = 0; i <= 25; i++)
        {

            if (arr[i] == 0 || i == n / k)
            {
                ans += 'a' + i;
                break;
            }
            arr[i]--;
        }
    }

    for (int i = ans.size(); i < k; i++)
    {
        ans += "a";
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
