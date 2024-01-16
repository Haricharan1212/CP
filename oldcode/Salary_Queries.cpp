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

template <class T>
class segtree
{
public:
    vector<T> t;
    int n;
    function<T(T, T)> op;
    T null;

    segtree(vector<T> &arr, function<T(T, T)> op, T null = 0)
    {
        // arr is the input array, op is the operation, null is the default element
        n = arr.size();
        this->op = op;
        this->null = null;

        t.resize(2 * n, null);

        for (int i = 0; i < n; ++i)
            t[n + i] = arr[i];

        for (int i = n - 1; i > 0; --i)
            t[i] = op(t[i << 1], t[i << 1 | 1]);
    }

    void modify(int p, int value)
    {
        // zero indexed

        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p ^ 1]);
    }

    T query(int l, int r)
    {
        // minimum in range [l, r) (r is excluded), zero indexed
        T res = null;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = op(res, t[l++]);
            if (r & 1)
                res = op(res, t[--r]);
        }
        return res;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vi a(n);
    map<int, int> mp;

    rep(i, 0, n) cin >> a[i], mp[a[i]] = 1;

    // segtree<int> st(a, [](int x, int y) { return x + y; }, 0LL);

    vector<pair<char, pi>> pts(q);

    rep(i, 0, q)
    {
        char type;
        cin >> type;

        pts[i].first = type;
        if (type == '!')
        {
            int k, x;
            cin >> k >> x;

            pts[i].second = {k, x};
            mp[x] = 1;
        }
        else
        {
            int a, b;
            cin >> a >> b;

            pts[i].second = {a, b};
        }
    }

    int cnt = 0;
    for (auto &i : mp)
    {
        i.second = cnt++;
    }

    rep(i, 0, n) a[i] = mp[a[i]];

    vi ans(cnt, 0);

    rep(i, 0, n) ans[a[i]]++;

    segtree<int> st(
        ans, [](int x, int y)
        { return x + y; },
        0LL);

    rep(i, 0, q)
    {
        // for (auto &i: st.t) cout << i << " ";

        char type = pts[i].first;

        // cout << type << " " << pts[i].second.first << " " << pts[i].second.second << "\n";
        // for (auto &i : mp)
        // {
        //     cout << i.first << "-" << i.second << " ";
        // }
        // cout << endl;
        // for (auto &i : a)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        // for (auto &i : st.t)
        //     cout << i << " ";
        // cout << "\n";

        if (type == '!')
        {
            int k = pts[i].second.first;
            int x = pts[i].second.second;

            k--;
            x = mp[x];
            int num = st.query(a[k], a[k] + 1);
            st.modify(a[k], num - 1);
            a[k] = x;

            num = st.query(a[k], a[k] + 1);
            st.modify(a[k], num + 1);
        }
        else if (type == '?')
        {
            int l = pts[i].second.first;
            int r = pts[i].second.second;

            if (mp.lower_bound(l) == mp.end())
            {
                cout << "0\n";
                continue;
            }

            if (mp.upper_bound(r) == mp.begin())
            {
                cout << "0\n";
                continue;
            }

            l = mp.lower_bound(l)->second;
            r = (--mp.upper_bound(r))->second;

            // cout << l << " " << r << "\n";

            cout << st.query(l, r + 1) << "\n";
        }
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