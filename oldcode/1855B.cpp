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

// P (x < a) ->  a / k
// P (max(a1, a2.. an) < x) -> a^n / k^n
// P (max(a1, a2 ... an) < x) -> a^n / k^n - (a - 1)^n / k^n

// sum 1/k * i * ((i)/k)^(n - 1)

int modexp(int a, int b, int m)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

bool poss(int n, int numbers)
{
    int l = 1;
    int r = powl(n, 1.0 / numbers);

    int prod = 1;

    while (l < r)
    {
        int mid = (l + r) / 2;

        prod = 1;
        for (int i = 0; i < numbers; i++)
            prod *= mid + i;

        if (prod <= n)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    prod = 1;
    for (int i = 0; i < numbers; i++)
        prod *= l + i;

    cout << l << ' ';

    return prod == n;
}

void solve()
{
    int n;
    cin >> n;

    cout << poss(n, 2) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
