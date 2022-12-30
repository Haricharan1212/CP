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
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref = a;
    vector<ll> xo = a;

    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1], xo[i] ^= xo[i - 1];

    for (int _ = 0; _ < q; _++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int mindist = r - l;
        pair<int, int> ans = {l, r};
        int i = l;
        int j = r;
        int xooo = pref[j] - (i == 0 ? 0 : pref[i - 1]) - (xo[j] ^ (i == 0 ? 0 : xo[i - 1]));

        for (; i < min(l + 32, n); i++)
            for (; j >= max(i, max(0, r - 32)); j--)
            {
                //                cout << pref[j] - (i == 0 ? 0 : pref[i - 1]) - (xo[j] ^ (i == 0 ? 0 : xo[i - 1]));

                if ((pref[j] - (i == 0 ? 0 : pref[i - 1]) - (xo[j] ^ (i == 0 ? 0 : xo[i - 1]))) == xooo)
                {
                    if ((j - i) < mindist)
                    {
                        // cout << "hi";
                        // cout << mindist << j - i << i << j;
                        mindist = j - i;
                        ans = make_pair(i, j);
                    }
                }
            }

        cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
    }
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
