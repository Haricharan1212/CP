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

    vi a(n);
    map<int, vector<int>> m;
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
        m[a[i]].push_back(i);
    }

    vi b(n, -1), c(n, -1);

    si bb, cc;

    if (m[n - 1].size() > 2)
    {
        cout << "NO" << endl;
        return;
    }
    else if (m[n - 1].size() == 0)
    {
        cout << "NO" << endl;
        return;
    }
    else if (m[n - 1].size() == 1)
    {
        b[m[n - 1][0]] = n - 1;
        c[m[n - 1][0]] = n - 1;
    }
    else if (m[n - 1].size() == 2)
    {
        b[m[n - 1][0]] = n - 1;
        cc.insert(m[n - 1][0]);
        c[m[n - 1][1]] = n - 1;
        bb.insert(m[n - 1][1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (m[i].size() > 2)
        {
            cout << "NO" << endl;
            return;
        }
        else if (m[i].size() == 0)
        {
            if (bb.size() == 0 || cc.size() == 0)
            {
                cout << "NO" << endl;
                return;
            }

            int num = *bb.begin();
            bb.erase(num);
            b[num] = i;

            num = *cc.begin();
            cc.erase(num);
            c[num] = i;
        }
        else if (m[i].size() == 1)
        {
            if (bb.size() == 0 && cc.size() == 0)
            {
                b[m[i][0]] = i;
                c[m[i][0]] = i;
            }
            else if (cc.size() == 0)
            {
                int num = *bb.begin();
                bb.erase(num);
                b[num] = i;

                c[m[i][0]] = i;
                bb.insert(m[i][0]);
            }
            else
            {
                int num = *cc.begin();
                cc.erase(num);
                c[num] = i;

                b[m[i][0]] = i;
                cc.insert(m[i][0]);
            }
        }
        else
        {
            b[m[i][0]] = i;
            cc.insert(m[i][0]);
            c[m[i][1]] = i;
            bb.insert(m[i][1]);
        }
    }

    cout << "YES" << endl;

    for (auto i : b)
        cout << i + 1 << ' ';
    cout << endl;

    for (auto i : c)
        cout << i + 1 << ' ';
    cout << endl;
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
