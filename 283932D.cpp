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

struct S
{
    int t, z, y;
};

bool check(vector<S> &a, int x, int m)
{
    int num = 0;
    int n = a.size();

    rep(i, 0, n)
    {
        int rem = x % (a[i].t * a[i].z + a[i].y);
        num += a[i].z * (x / (a[i].t * a[i].z + a[i].y)) + (min(rem, a[i].t * a[i].z)) / a[i].t;
    }

    return num >= m;
}

void print(vector<S> &a, int x, int m)
{
    int n = a.size();
    rep(i, 0, n)
    {
        int rem = x % (a[i].t * a[i].z + a[i].y);
        int poss = a[i].z * (x / (a[i].t * a[i].z + a[i].y)) + (min(rem, a[i].t * a[i].z)) / a[i].t;

        if (m >= poss)
        {
            m -= poss;
            cout << poss << ' ';
        }
        else
        {
            cout << m << ' ';
            m = 0;
        }
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<S> a(n);

    rep(i, 0, n) cin >> a[i].t >> a[i].z >> a[i].y;

    int l = 0, r = 3000001;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (check(a, mid, m))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << endl;
    print(a, l, m);
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
