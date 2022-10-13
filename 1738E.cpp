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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vi pref(n + 1, 0), suf(n + 1, 0);

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    pref[0] = -1, suf[n] = -2;

    int leftpoint = 0, rightpoint = n;

    int count = 1;
    while (leftpoint != rightpoint)
    {
        if (pref[leftpoint] < suf[rightpoint])
        {
            leftpoint++;
        }
        else if (pref[leftpoint] > suf[rightpoint])
        {
            rightpoint--;
        }
        else
        {
            count++;
            leftpoint++;
        }
    }

    int ans = 1;
    for (int i = 1; i < count; i++)
        ans *= i;

    if (pref[leftpoint] == suf[rightpoint])
        ans *= count;
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
