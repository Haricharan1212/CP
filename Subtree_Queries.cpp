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
    T nullval;

    segtree(vector<T> &arr, function<T(T, T)> op, T nullval)
    {
        // arr is the input array, op is the operation, null is the default element
        n = arr.size();
        this->op = op;
        this->nullval = nullval;

        t.resize(2 * n, nullval);

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
};

void dfs(int node, vii &adj, vi &in, vi &out, vi &ord, int parent, int &time)
{
    ord[node] = time;
    in[node] = time;
    time++;

    for (int child : adj[node])
    {

        if (parent != child)
        {
            dfs(child, adj, in, out, ord, node, time);
        }
    }

    out[node] = time - 1;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vi cols(n);
    rep(i, 0, n) cin >> cols[i];

    vii adj(n);
    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi in(n), out(n), ord(n);
    int time = 0;

    dfs(0, adj, in, out, ord, -1, time);

    // for (auto i : ord)
    //     cout << i << ' ';
    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << in[i] << ' ' << out[i] << endl;
    // }

    vi new_cols(n);

    rep(i, 0, n)
    {
        new_cols[ord[i]] = cols[i];
    }

    segtree<int> st(
        new_cols, [](int a, int b)
        { return a + b; },
        0LL);

    vi revord(n);
    rep(i, 0, n) revord[ord[i]] = i;

    rep(_, 0, q)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;
            s = ord[s];

            st.modify(s, x);
        }
        else
        {
            int s;
            cin >> s;
            s--;

            int a = in[s];
            int b = out[s];

            cout << st.query(a, b + 1) << endl;
        }

        // rep(i, 0, n) cout << st.query(i, i + 1) << ' ';
        // cout << endl;
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