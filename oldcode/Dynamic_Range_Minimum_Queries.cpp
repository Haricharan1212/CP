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

int f(int a, int b)
{
    return min(a, b);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (int &i : arr)
        cin >> i;

    segtree<int> st(arr, f, (int)1e9 + 7);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, u;
            cin >> k >> u;
            k--;
            st.modify(k, u);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << st.query(l, r + 1) << "\n";
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