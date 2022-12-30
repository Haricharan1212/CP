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
    deque<char> d;
    string s;
    cin >> s;

    int rev = 0;

    for (int i = 1; i <= n; i++)
    {
        if (rev)
            d.push_front(s[i - 1]);
        else
            d.push_back(s[i - 1]);
        if (i % 2 == 1)
        {
            rev += 1;
            rev %= 2;
        }
    }

    if (n % 4 == 2 || n % 4 == 1)
        reverse(d.begin(), d.end());

    for (int i = 0; i < n; i++)
        cout
            << d[i];

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
