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

    string a, b;
    cin >> a >> b;

    if (a[0] == b[0])
    {
        cout << "YES" << endl;
        cout << a[0] << "*" << endl;
        return;
    }

    if (a[a.size() - 1] == b[b.size() - 1])
    {
        cout << "YES" << endl;
        cout << "*" << a[a.size() - 1] << endl;
        return;
    }

    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < b.size() - 1; j++)
        {
            if (a[i] == b[j] && a[i + 1] == b[j + 1])
            {
                cout << "YES" << endl;
                cout << "*" << a[i] << a[i + 1] << "*" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;

    int jprev = -1;

    string ans = "!!";

    for (int i = 0; i < a.size(); i++)
    {
        int flag = 0;
        for (int j = jprev + 1; j < b.size(); j++)
            if (a[i] == b[j])
            {
                jprev = j;
                ans += a[i];
                flag = 1;
                break;
            }
            else
            {
                if (ans[ans.size() - 1] != '*')
                    ans += '*';
            }
        if (flag == 0 && ans[ans.size() - 1] != '*')
            ans += '*';
    }

    if (jprev != (b.size() - 1) && ans[ans.size() - 1] != '*')
        ans += '*';

    int count = 0;
    for (auto i : ans)
        if (i == '*')
            count++;
    if (count <= ans.size() - 2 - count)
    {
        cout << "YES" << endl;
        cout << ans.substr(2, ans.size() - 2) << endl;
    }
    else
        cout << "NO" << endl;
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
