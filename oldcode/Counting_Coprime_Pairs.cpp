// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

vi s;

vector<int> sieve(int n)
{
    vector<int> primes(n + 1, -1);

    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == -1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (primes[j] == -1)
                    primes[j] = i;
            }
        }
    }
    return primes;
}

int getFactors(int n)
{
    set<int> ss;

    if (s[n] == -1)
    {
        return n;
    }

    while (n != 1)
    {
        if (s[n] == -1)
        {
            ss.insert(n);
            break;
        }

        ss.insert(s[n]);
        n /= s[n];
    }

    int prod = 1;

    for (auto i : ss)
        prod *= i;

    return prod;
}

int numfactors(int n)
{
    set<int> ss;

    if (s[n] == -1)
    {
        return 1;
    }

    while (n != 1)
    {
        if (s[n] == -1)
        {
            ss.insert(n);
            break;
        }

        ss.insert(s[n]);
        n /= s[n];
    }

    return ss.size();
}

void solve()
{
    int n;
    cin >> n;
    s = sieve(1e6 + 5);

    map<int, int> m;

    int nn = n;

    rep(i, 0, n)
    {
        int x;
        cin >> x;

        if (x == 1)
            nn--;
        else
            m[getFactors(x)]++;
    }

    int cnt = 0;

    int ans = 0;

    for (auto i : m)
    {
        cout << i.first << ' ' << i.second << ' ' << numfactors(i.first) << endl;

        cnt += i.second;

        if (numfactors(i.first) % 2 == 0)
        {
            ans -= ((i.second) * (i.second - 1)) / 2;
        }
        else
        {
            ans += ((i.second) * (i.second - 1)) / 2;
        }
    }

    cout << (cnt * (cnt - 1)) / 2 - ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
