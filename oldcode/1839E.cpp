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

    vector<pi> a(n);
    multiset<int, greater<int>> s;
    vi b(n);
    rep(i, 0, n)
    {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }

    sort(a.begin(), a.end());

    multiset<pi> ss;
    rep(i, 0, n) s.insert(a[i].first), ss.insert(a[i]);

    while (s.size() >= 2)
    {
        int num = *s.begin();
        s.erase(s.begin());
        int numm = *(s.begin());
        s.erase(s.begin());
        num -= numm;

        if (num)
            s.insert(num);
    }

    int flag = 0;

    if (s.size() == 0)
    {
        cout << "Second" << endl;
        cout.flush();
        flag = 2;
    }
    else
    {
        cout << "First" << endl;
        flag = 1;
    }

    if (flag == 1)
    {

        while (true)
        {
            // for (auto i : ss)
            //     cout << i.first << 'x' << i.second << ' ';

            pi num = *ss.rbegin();
            cout << num.second + 1 << endl;
            ss.erase((--(ss.end())));

            int j;
            cin >> j;
            if (j == 0)
            {
                return;
            }
            if (j == -1)
            {
                cout << "WA" << endl;
                return;
            }

            j--;

            ss.erase({b[j], j});

            if (num.first - b[j])
                ss.insert({num.first - b[j], num.second});

            b[num.second] -= b[j];
            b[j] = 0;
        }
    }
    else
    {
        while (true)
        {
            // cout << ss.size() << endl;
            // for (auto i : ss)
            //     cout << i.first << 'x' << i.second << ' ';

            int x;
            cin >> x;
            fflush(stdout);

            if (x == 0)
            {
                exit(0);
                return;
            }
            // for (auto i : ss)
            //     cout << i.first << 'x' << i.second << ' ';

            if (x == -1)
            {
                cout << "WA" << endl;
                return;
            }

            x--;
            int j;
            if (x == ss.rbegin()->second)
            {
                j = (++ss.rbegin())->second;

                if (b[x] - b[j])
                    ss.insert({b[x] - b[j], x});
            }
            else
            {
                j = ss.rbegin()->second;

                if (b[j] - b[x])
                    ss.insert({b[j] - b[x], j});
            }

            cout << j + 1 << endl;
            fflush(stdout);

            ss.erase({b[j], j});
            ss.erase({b[x], x});

            int z = min(b[x], b[j]);
            b[j] -= z;
            b[x] -= z;

            if (ss.size() == 0)
            {
                int x;
                cin >> x;
                fflush(stdout);

                if (x == 0)
                    return;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
