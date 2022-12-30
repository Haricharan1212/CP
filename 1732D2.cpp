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

const int n = 1e5 + 5;
bool prime[n + 1];

void sieve()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void solve()
{
    ll q;
    cin >> q;
    map<ll, ll> m;
    set<ll> s = {0};
    set<int> deleted;
    for (ll i = 0; i < q; i++)
    {
        char x;
        cin >> x;
        ll a;
        cin >> a;
        // cout << x << a;
        if (x == '+')
        {
            s.insert(a);
        }
        else if (x == '-')
        {
            s.erase(a);
            deleted.insert(a);
        }
        else
        {
            if (m[a] && !s.count(a) && !deleted.count(a))
            {
                cout << m[a] << endl;
            }
            else if (m[a] && !s.count(a) && !deleted.count(a))
            {
            }
            else
            {
                ll ans = m[a];
                while (s.count(ans))
                {
                    ans += a;
                }
                cout << ans << endl;
                m[a] = ans;
            }
        }
    }
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
