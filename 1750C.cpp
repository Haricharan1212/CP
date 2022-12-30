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

const int N = 1e5 + 5;
bool prime[N + 1];

void sieve()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    string a;
    cin >> a;

    string b;
    cin >> b;
    vector<pair<int, int>> v;

    if (a == b)
        1;
    else
    {
        v.push_back({0, n - 1});
        for (int i = 0; i < n; i++)
        {
            a[i] = ('0' + '1' - a[i]);
        }

        if (a != b)
        {
            cout << "NO" << endl;
            return;
        }
        else
            cout << "YES" << endl;
    }
    int current = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == '1' && current % 2 == 0)
        {
            a[i] = '0';
            current++;
            v.push_back({0, i});
        }
        else if (a[i] == '0' && current % 2 == 1)
        {
            a[i] = 1;
            current++;
            v.push_back({0, i});
        }
    }

    v.push_back({0, 1});
    v.push_back({1, n - 1});

    cout << v.size() << endl;

    for (auto i : v)
        cout << i.first + 1 << ' ' << i.second + 1 << endl;
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
