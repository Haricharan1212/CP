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

    string s;
    cin >> s;

    int n = s.size();

    int arr[26] = {0};
    multiset<int> mm;

    for (auto i : s)
    {
        arr[i - 'a']++;
        mm.insert(i - 'a');
    }
    sort(s.begin(), s.end());

    vi start;
    vi end;

    int flag = 0;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = 0; j < (arr[i]) / 2; j++)
            {
                start.push_back(i);
                end.push_back(i);
                mm.erase(mm.find(i));
                mm.erase(mm.find(i));
            }
        }
        else
        {
            for (int j = 0; j < (arr[i]) / 2; j++)
            {
                start.push_back(i);
                end.push_back(i);
                mm.erase(mm.find(i));
                mm.erase(mm.find(i));
            }
            start.push_back(i);
            mm.erase(mm.find(i));
            for (auto i : mm)
                end.push_back(i);
            break;
        }
    }

    vector<int> arrr;

    for (auto i : start)
        arrr.push_back(('a' + i));
    reverse(end.begin(), end.end());
    for (auto i : end)
        arrr.push_back(('a' + i));

    vi ar = arrr;

    reverse(arrr.begin(), arrr.end());

    if (ar > arrr)
        arrr = ar;
    // for (auto i : arrr)
    //     cout << (char)i;
    // cout << ' ';
    for (int i = n - 1; i > n / 2; i--)
    {
        if (arrr[(n) / 2] > arrr[i] && arrr[i] < arrr[n - 1 - i] && arrr[n - 1 - i] >= arrr[n / 2])
        {
            swap(arrr[(n) / 2], arrr[i]);
        }
    }
    for (auto i : arrr)
        cout << (char)i;

    // for (auto i : arr)
    //     cout << i << ' ';

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
