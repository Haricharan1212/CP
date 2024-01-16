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

struct arr
{
    int ops;
    vector<string> s;
    int index;
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<arr> v(k + 1);
    rep(i, 0, k + 1)
    {
        string a, b, c;
        cin >> a >> b >> c;

        v[i].s = {a, b, c};

        v[i].index = i;

        rep(j, 1, n - 1)
        {
            rep(l, 1, m - 1)
            {
                if (v[i].s[j][l] == '1' && v[i].s[j - 1][l] == '0' && v[i].s[j - 1][l] == '0' && v[i].s[j][l + 1] == '0' && v[i].s[j][l - 1] == '0')
                    v[i].ops++;
                if (v[i].s[j][l] == '0' && v[i].s[j - 1][l] == '1' && v[i].s[j - 1][l] == '1' && v[i].s[j][l + 1] == '1' && v[i].s[j][l - 1] == '1')
                    v[i].ops++;
            }
        }
    }

    sort(v.begin(), v.end(), [](arr a, arr b)
         { return a.ops < b.ops; });
    reverse(v.begin(), v.end());

    vector<string> strings;

    cout << v[0].index + 1 << endl;
    rep(i, 0, k)
    {
        int flag = 1;
        rep(j, 0, n)
            rep(l, 0, m) if (v[i].s[j][l] != v[i + 1].s[j][l])
        {
            string str = "1 ";
            str += to_string(j + 1);
            str += " ";
            str += to_string(l + 1);
            strings.push_back(str);
            flag = 0;
            strings.push_back("2 " + to_string(v[i + 1].index + 1));
        }
        if (flag)
            strings.push_back("2 " + to_string(v[i + 1].index + 1));
    }

    cout << strings.size() << endl;
    for (auto i : strings)
        cout << i << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
