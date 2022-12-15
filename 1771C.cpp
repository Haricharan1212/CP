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

set<int> a;

bool primeFactors(int n)
{
    int flag = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (a.count(i))
            {
                cout << "YES" << endl;
                return true;
            }
            a.insert(i);
            flag = 1;
        }
    }
    if (flag == 0)
        a.insert(n);

    return false;
}

void solve()
{
    a = {};
    int n;
    cin >> n;

    int flag = 0;

    for (int i = 0; i < n; i++)
    {

        int f;
        cin >> f;
        if (primeFactors(f))
            flag = 1;
    }
    if (!flag)
        cout << "NO" << endl;
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
