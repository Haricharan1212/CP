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

vi distinctPrimeFactors(int N)
{
    if (N < 2)
    {
        return {-1};
    }
    if (N == 2)
    {

        return {2};
    }

    vi ans;

    unordered_map<int, bool> visited;

    for (int i = 2; i * i <= N; i++)
    {
        while (N % i == 0)
        {
            if (!visited[i])
            {
                ans.push_back(i);
                visited[i] = 1;
            }
            N /= i;
        }
    }
    if (N > 2)
        ans.push_back(N);
    return ans;
}

bool check(vector<pi> &a, int n, int m, int k, map<pi, bool> ss)
{

    int num = n / k;
    for (auto i : ss)
    {
        if (i.second == true)
            continue;

        for (int j = 0; j < n; j += num)
        {
            // cout << i.first.first + j << " " << i.first.second + j << endl;

            if (ss.find({(i.first.first + j) % n, (i.first.second + j) % n}) == ss.end() && ss.find({(i.first.second + j) % n, (i.first.first + j) % n}) == ss.end())
                return false;
            if (ss.find({(i.first.first + j) % n, (i.first.second + j) % n}) != ss.end())
                ss[{(i.first.first + j) % n, (i.first.second + j) % n}] = true;
            else
                ss[{(i.first.second + j) % n, (i.first.first + j) % n}] = true;
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pi> a(m);
    map<pi, bool> ss;
    rep(i, 0, m)
    {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;

        ss[a[i]] = false;
    }

    vi f = distinctPrimeFactors(n);

    // if (f.size() == 1 && f[0] == n)
    // {
    //     cout << "No" << endl;
    //     return;
    // }

    for (auto i : f)
    {
        bool k = check(a, n, m, i, ss);

        if (k)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
