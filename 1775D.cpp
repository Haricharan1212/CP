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

vector<int> sieve(int n)
{
    vector<int> isPrime(n + 1, -1);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == -1)
        {
            if (i * i <= n)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    if (isPrime[j] == -1)
                        isPrime[j] = i;
                }
            }
        }
    }
    return isPrime;
}
vi primes;

si divisors(int n)
{
    if (primes[n] == -1)
        return {n};
    si ans;
    while (primes[n] != -1)
    {
        int num = primes[n];
        ans.insert(num);

        while (n % num == 0)
            n /= num;
    }
    ans.insert(n);
    ans.erase(1);
    return ans;
}

const int mx = 3e5 + 5;

vi p;

void dfs(vector<si> &adj, int start, vb &vis, vi &path, int t)
{
    cout << start << ' ';
    vis[start] = true;
    path.push_back(start);

    if (start == t)
    {
        p = path;
        return;
    }

    for (auto &i : adj[start])
    {
        if (!vis[i])
            dfs(adj, i, vis, path, t);
    }

    path.pop_back();
    vis[start] = false;
}

void solve()
{
    primes = sieve(mx);
    int n;
    cin >> n;

    vi a(n);
    vector<si> adj(mx);
    map<int, int> m;
    rep(i, 0, n)
    {
        cin >> a[i];

        si divs = divisors(a[i]);
        m[a[i]] = i;
        for (auto &j : divs)
        {
            adj[j].insert(a[i]);
            adj[a[i]].insert(j);
        }
    }

    int s, t;
    cin >> s >> t;

    s--, t--;

    int start = a[s];
    vb vis(mx, false);
    vi path;
    int end = a[t];
    dfs(adj, start, vis, path, end);

    if (p.size() == 0)
        cout << -1 << endl;
    else
    {
        cout << p.size() << endl;

        if (p.size() == 1)
        {
            cout << start << endl;
        }

        cout << start << " ";

        rep(i, 1, p.size() - 1) cout << i << ' ';
        cout << end << ' ';
        cout << endl;
    }
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
