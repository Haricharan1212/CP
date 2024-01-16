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

    void modify(int p, T value)
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

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vi a = arr, b = arr;
    rep (i, 0, n) a[i] -= i;
    rep (i, 0, n) b[i] += i;

    segtree<int> sa(a, [](int a, int b){return min(a, b);}, 1e18);
    segtree<int> sb(b, [](int a, int b){return min(a, b);}, 1e18);

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k, x;
            cin >> k >> x;
            k--;

            sa.modify(k, x - k);
            sb.modify(k, x + k);

            arr[k] = x;
        }
        else
        {
            int k;
            cin >> k;
            k--;

            // for (auto x : sa.t) cout << x << " ";
            // cout << "\n";

            // for (auto x : sb.t) cout << x << " ";
            // cout << "\n";

            int ans = min(sa.query(0, k + 1) + k, sb.query(k, n) - k);
            cout << ans << "\n";
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
 //   cin >> tc;
    while (tc--)
        solve();

    return 0;
}