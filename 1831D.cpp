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

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)

vector<int> sieve(int n)
{
    vector<int> is_prime(n + 1, -1);

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == -1 && 1LL * i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                if (is_prime[j] == -1)
                    is_prime[j] = i;
        }
    }
    return is_prime;
}

vi prims;

vector<pi> f(int x)
{
    vector<pi> ans;
    while (prims[x] != -1)
    {
        int num = prims[x];
        int cnt = 0;
        while (x % num == 0)
        {
            x /= num;
            cnt++;
        }

        ans.push_back({num, cnt});
    }

    if (x != 1)
        ans.push_back({x, 1});

    return ans;
}

void generateDivisors(int curIndex, int curDivisor,
                      vector<pi> &arr, vector<int> &divisors)
{
    if (curIndex == arr.size())
    {
        // cout << curDivisor << ' ';
        divisors.push_back(curDivisor);
        return;
    }

    for (int i = 0; i <= arr[curIndex].second; ++i)
    {
        generateDivisors(curIndex + 1, curDivisor, arr, divisors);
        curDivisor *= arr[curIndex].first;
    }
}

vii divisorss;

void solve()
{
    int n;
    cin >> n;

    vi a(n), b(n);
    unordered_map<int, vi> m;
    rep(i, 0, n)
    {
        cin >> a[i];
        m[a[i]].push_back(i);
    }

    unordered_map<pi, vi> mmm;
    rep(i, 0, n)
    {
        cin >> b[i];
        mmm[{a[i], b[i]}].push_back(i);
    }

    int ans = 0;

    rep(num, 2, 2 * n + 2)
    {
        for (auto i : divisorss[num])
        {
            // cout << num << ' ' << i << ' ' << num / i << endl;
            if (m.find(i) == m.end())
                continue;
            if (m.find(num / i) == m.end())
                continue;

            // cout << i << ' ' << num / i << endl;

            for (auto j : m[i])
            {
                pi req = {num / i, num - b[j]};

                if (mmm.find(req) == mmm.end())
                    continue;

                // if (upper_bound(mmm[req].begin(), mmm[req].end(), j) == mmm[req].end())
                //     continue;

                int f = (upper_bound(mmm[req].begin(), mmm[req].end(), j - 1) - mmm[req].begin());
                // cout << req.first << ' ' << req.second << 'h';
                // cout << i << ' ' << num / i << ' ' << j << ' ' << f << endl;

                // for (auto i : mmm[req])
                //     cout << i << 'k';
                // cout << endl;
                ans += max(f, 0);
                // cout << i << ' ' << num / i << ' ' << j << ' ' << ans << endl;

                // for (auto k : m[num / i])
                // {
                //     if (j < k)
                //     {
                //         if (num == b[j] + b[k])
                //         {
                //             cout << a[j] << ' ' << a[k] << ' ' << b[j] << ' ' << b[k] << endl;
                //             cout << j << ' ' << k << endl;
                //             ans++;
                //         }
                //     }
                // }
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    prims = sieve(2 * 2000005);

    rep(i, 0, 2 * 2e5 + 5)
    {
        if (i <= 1)
        {
            divisorss.push_back({});
            continue;
        }

        vector<pi> ff = f(i);
        vi divisors;
        generateDivisors(0, 1, ff, divisors);

        divisorss.push_back(divisors);
    }

    while (tc--)
    {
        solve();
    }

    return 0;
}
