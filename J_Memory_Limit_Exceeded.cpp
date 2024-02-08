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
#define ll long long

using implicit_segtree = struct implicit_segtree;
using T = long long;

struct implicit_segtree
{
    implicit_segtree *child[2];
    T v;
    static const ll implicit_sz = 1.1e9;
    static const T base = 0;

    implicit_segtree()
    {
        v = base;
        child[0] = nullptr;
        child[1] = nullptr;
    }

    implicit_segtree *ch(int x)
    {
        if (!child[x])
            child[x] = new implicit_segtree();
        return child[x];
    }

    inline T op(T a, T b)
    {
        return a + b;
    }

    void upd(ll loc, T val)
    {
        upd(loc, val, 0, implicit_sz - 1);
    }

    T upd(ll loc, T val, ll l, ll r)
    {
        if (l > loc || r < loc)
            return v;
        if (l == r)
            return v = val;
        ll m = (l + r) / 2;
        T a = base, b = base;
        if (loc <= m)
        {
            a = ch(0)->upd(loc, val, l, m);
            if (child[1])
                b = ch(1)->v;
        }
        else
        {
            if (child[0])
                a = ch(0)->v;
            b = ch(1)->upd(loc, val, m + 1, r);
        }

        return v = op(a, b);
    }

    T query(ll ql, ll qr)
    {
        return query(ql, qr, 0, implicit_sz - 1);
    }

    T query(ll ql, ll qr, ll tl, ll tr)
    {
        if (qr < tl || ql > tr || tl > tr)
            return base;
        if (ql <= tl && tr <= qr)
            return v;
        T a = base, b = base;
        ll m = (tl + tr) / 2;
        if (child[0])
            a = ch(0)->query(ql, qr, tl, m);
        if (child[1])
            b = ch(1)->query(ql, qr, m + 1, tr);
        return op(a, b);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    implicit_segtree st;

    const int init = 0;

    while (q--)
    {
        int t;
        cin >> t;

        // rep (i, 0, n + 1)
        // {
        //     cout << st.query(i, i)<< " ";
        // }
        // cout << endl;

        if (t == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;

            int num = st.query(a, a);
            int num1 = st.query(b + 1, b + 1);

            st.upd(a, num + u);            
            st.upd(b + 1, num1 -u);

            // cout << num1 << " " << num << endl;
        }
        else
        {
            int a;
            cin >> a;
            cout << st.query(0, a) << " ";
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