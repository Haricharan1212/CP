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

    string s;
    cin >> s;

    vi arr(26, 0);

    for (auto i : s)
        arr[i - 'a']++;

    vi b = arr;
    sort(b.begin(), b.end(), greater<int>());

    vi a;

    int anss = 1e9;

    int minindex = 1;

    for (int i = 1; i <= 26; i++)
    {
        if (n % i == 0)
        {
            int g = 0;
            int f = 0;
            for (int j = 0; j < i; j++)
            {
                f += max(0ll, b[j] - n / i);
                g += -min(0ll, b[j] - n / i);
            }

            for (int j = i; j < 26; j++)
                g += b[j];

            int ans = (abs(f - g) + 1) / 2 + min(f, g);
            if (ans < anss)
            {
                {
                    anss = min(ans, anss);
                    minindex = i;
                }
            }
        }
    }

    int ff = minindex;

    si more;
    si less;

    for (int i = 0; i < ff; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (b[i] == arr[j] && arr[j] > n / ff && !(more.count(j)) && !(less.count(j)))
            {
                more.insert(j);
                break;
            }
            else if (b[i] == arr[j] && arr[j] < n / ff && !(more.count(j)) && !(less.count(j)))
            {
                less.insert(j);
                break;
            }
        }
    }

    // while (more.size() + less.size() < ff)
    // {
    //     for (int i = 0; i < 26; i++)
    //         if (!less.count(i) && !more.count(i))
    //         {
    //             less.insert(i);
    //             ff++;
    //         }
    // }

    cout << anss << endl;

    // for (auto i : more)
    //     cout << i << ' ';

    // cout << endl;

    // for (auto i : less)
    //     cout << i << ' ';

    // cout << endl;

    for (int i = 0; i < n; i++)
    {

        int c = s[i] - 'a';
        if (arr[c] == n / ff)
            continue;

        if (more.count(c) || (!more.count(c) && !less.count(c)))
        {
            char f = *less.begin() + 'a';
            s[i] = f;
            arr[f - 'a']++;
            arr[c]--;

            // cout << arr[*less.begin()];

            if (arr[*less.begin()] == n / ff)
                less.erase(less.begin());
        }
    }

    cout << s << endl;
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
