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

multiset<int> primeFactors(int n)
{
    multiset<int> a;
    int c = 2;
    while (n > 1)
    {
        if (n % c == 0)
        {
            a.insert(c);
            n /= c;
        }
        else
            c++;
    }
    return a;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    if (n % x != 0)
    {
        cout << -1 << endl;
        return;
    }

    vi ans(n);

    for (int i = 0; i < n; i++)
        ans[i] = i + 1;

    int f = n / x;
    multiset<int> a = primeFactors(f);

    ans[0] = x;
    ans[n - 1] = 1;

    while (!a.empty())
    {
        ans[x - 1] = x * (*a.begin());
        x *= (*a.begin());
        a.erase(a.begin());
    }

    for (auto i : ans)
        cout << i << ' ';
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
