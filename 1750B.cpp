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
    deque<int> a(n);
    int ones = 0, zeros = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0', a[i] == 0 ? zeros++ : ones++;
    }

    int best = ones * zeros;

    int zercount = 0;
    int onescount = 0;
    a[0] == 0 ? zercount++ : onescount++;
    best = max(zercount * zercount, best);
    best = max(onescount * onescount, best);

    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0 && zercount)
            zercount++;
        else if (a[i] == 1 && onescount)
            onescount++;
        else
        {
            zercount = 0;
            onescount = 0;
            a[i] == 0 ? zercount++ : onescount++;
        }
        best = max(zercount * zercount, best);
        best = max(onescount * onescount, best);
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    cout << best << endl;
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
