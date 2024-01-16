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

namespace internal
{
    unsigned int bit_ceil(unsigned int n)
    {
        unsigned int x = 1;
        while (x < (unsigned int)(n))
            x *= 2;
        return x;
    }
    int countr_zero(unsigned int n)
    {
#ifdef _MSC_VER
        unsigned long index;
        _BitScanForward(&index, n);
        return index;
#else
        return __builtin_ctz(n);
#endif
    }
    constexpr int countr_zero_constexpr(unsigned int n)
    {
        int x = 0;
        while (!(n & (1 << x)))
            x++;
        return x;
    }
}

template <class S, S (*op)(S, S), S (*e)()>
struct segtree
{
public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S> &v) : _n((int)(v.size()))
    {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++)
            d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--)
        {
            update(i);
        }
    }

    void set(int p, S x)
    {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }

    S get(int p) const
    {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const
    {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r)
        {
            if (l & 1)
                sml = op(sml, d[l++]);
            if (r & 1)
                smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

class S
{
public:
    int first;
    int last;
    int op;
    int size;

    void print(){
        cout << first << ' ' << last << ' ' << op << ' ' << size << endl;
    }
};

S op(S l, S r)
{
    if (l.first == -1) return r;
    if (r.first == -1) return l;

    S res;
    res.first = l.first;
    res.op = l.op + r.op;
    res.size = l.size + r.size;

    int num = max(0LL, l.last - r.first);
    res.op += r.size * num;
    res.last = r.last + num;

    return res;
}

S e()
{
    S res;
    res.first = -1;
    res.last = 0;
    res.size = 0;
    res.op = 0;

    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<S> a(n);
    rep(i, 0, n)
    {
        int x;
        cin >> x;

        a[i].first = a[i].last = x;
        a[i].op = 0;
        a[i].size = 1;
    }

    segtree<S, op, e> st(a);

    // cout << st.all_prod().ans << "\n";

    cout << st.prod(0, 4).op << ' ';

    // while (m--)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     a--, b--;
    //     cout << st.prod(a, b + 1).op << endl;
    // }
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