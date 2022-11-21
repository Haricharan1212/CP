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
    ll n, m;
    cin >> n >> m;
    ll z = n;

    ll two = 0, five = 0;
    while (n % 2 == 0)
        n /= 2, two++;
    while (n % 5 == 0)
        n /= 5, five++;

    if (two > five)
    {
        ll myans = 1;
        ll num = abs(two - five);
        ll ans = log2(m) / log2(5);

        if (ans > num)
        {
            myans = powl(5, num);
            while (myans * 10 <= m)
                myans *= 10;
            myans = (m / myans) * myans;
            cout << myans * z << endl;
        }
        else
        {
            myans = powl(5, ans);
            myans = (m / myans) * myans;
            cout << myans * z << endl;
        }
    }
    else if (two <= five)
    {
        ll myans = 1;
        ll num = abs(two - five);
        ll ans = log2(m) / log2(2);

        if (ans > num)
        {
            myans = powl(2, num);
            while (myans * 10 <= m)
                myans *= 10;
            myans = (m / myans) * myans;
            cout << myans * z << endl;
        }
        else
        {
            myans = powl(2, ans);
            myans = (m / myans) * myans;
            cout << myans * z << endl;
        }
    }

    else
        cout << n * m << endl;
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
