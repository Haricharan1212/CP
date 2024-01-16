// Haricharan
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")

#define vi vector<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

int mx = 1e9;

class Teacher
{
    int var;
    static int numteachers = 0;

    Teacher(int name)
    {
        var = name;
        numteachers++;
    }

    ~Teacher()
    {
        numteachers--;
    }
}

inline void
summs(vi &l, unordered_map<int, int> &ans, int &x)
{
    int n = l.size();

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                if (sum > x - l[j])
                {
                    flag = 1;
                    break;
                }
                sum += l[j];
            }
        }
        if (flag)
            continue;
        ans[sum]++;
    }
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vi a(n);
    vi l, r;

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    rep(i, 0, n)
    {
        if (i % 2)
            l.push_back(a[i]);
        else
            r.push_back(a[i]);
    }

    unordered_map<int, int> f, ff;

    summs(l, f, x);
    summs(r, ff, x);

    long long ans = 0;

    for (auto i : f)
    {
        if (ff.count(x - i.first))
            ans += (long long)i.second * ff[x - i.first];
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
