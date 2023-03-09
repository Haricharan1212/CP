// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

int modexp(long long x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

vector<bool> sieve(int n)
{
    // Time Complexity:- O(log(log(n)))

    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && 1LL * i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return is_prime;
}

void solve()
{
    int n;
    cin >> n;

    set<int> s;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    vi b = a;
    sort(b.begin(), b.end());

    if (b[0] == 1 && b[n - 1] == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (b[0] == 1 && s.size() >= 2)
    {
        cout << -1 << endl;
        return;
    }

    if (b[0] == b[n - 1])
    {
        cout << 0 << endl;
        return;
    }

    map<int, vi> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]].push_back(i);
    }

    vector<pair<int, int>> ans;

    int num = 0;
    int numm = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it == m.begin())
        {
            num = (*it).first;
            numm = ((*it).second)[0];
        }
        else
        {
            int count = 0;
            int f = (*it).first;
            while (f > num)
            {
                f = (f + num - 1) / num;
                count++;
            }
            for (auto jj : (*it).second)
                for (int j = 0; j < count; j++)
                    ans.push_back({jj, numm});

            m[f] = (*it).second;
            m[(*it).first] = {};

            if (f < num)
            {
                num = f;
                it = m.begin();
                num = (*it).first;
                numm = ((*it).second)[0];
            }
        }
        // if (ans.size() > 30 * n)
        // {
        //     cout << 0 << endl;
        //     return;
        // };
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}