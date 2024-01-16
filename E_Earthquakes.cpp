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
    long long n;
    function<T(T, T)> op;
    T nullval;

    segtree(vector<T> &arr, function<T(T, T)> op, T nullval)
    {
        // arr is the input array, op is the operation, null is the default element
        n = arr.size();
        this->op = op;
        this->nullval = nullval;

        t.resize(2 * n, nullval);

        for (long long i = 0; i < n; ++i)
            t[n + i] = arr[i];

        for (long long i = n - 1; i > 0; --i)
            t[i] = op(t[i << 1], t[i << 1 | 1]);
    }

    void modify(long long p, T value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p ^ 1]);
    }

    T query(long long l, long long r)
    {
        // minimum in range [l, r) (r is excluded), zero indexed
        T res1 = nullval, res2 = nullval;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res1 = op(res1, t[l++]);
            if (r & 1)
                res2 = op(t[--r], res2);
        }

        T res = op(res1, res2);
        return res;
    }

    int query_pos(long long l, long long r, long long p)
    {
        // get minimum index in range [l, r), zero indexed
        if (l >= r) return -1;

        if (query(l, r) > p)
            return -1;

        if (l + 1 == r) {
            return l;
        }
        
        int mid = (l + r)/2;

        // cout << mid << ' ';
        // cout << query(l, mid + 1) << ' ' << query (mid + 1, r) << '\n';

        if (query(l, mid) <= p) {
            return query_pos(l, mid, p);
        } else {
            return query_pos(mid, r, p);
        }

        return -1;
    }
};

const int mx = 1e9 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;

    vi a(n, mx);

    segtree<int> st(
        a, [](int x, int y)
        { return min(x, y); },
        mx);

    // st.modify(0, 100);
    // st.modify(1, 49);

    // cout << st.query_pos(0, 2, 50);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            st.modify(x, y);
        }
        else
        {
            int l, r, p;
            cin >> l >> r >> p;

            int ans = 0;

            while (st.query_pos(l, r, p) != -1)
            {
                ans++;
                int index = st.query_pos(l, r, p);
                st.modify(index, mx);
            }
        
            cout << ans << endl;
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
        solve();

    return 0;
}