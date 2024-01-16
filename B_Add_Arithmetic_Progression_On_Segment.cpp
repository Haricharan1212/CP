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
        return __builtin_ctz(n);
    }
    constexpr int countr_zero_constexpr(unsigned int n)
    {
        int x = 0;
        while (!(n & (1 << x)))
            x++;
        return x;
    }
}

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree
{

public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S> &v) : _n((int)(v.size()))
    {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
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
        for (int i = log; i >= 1; i--)
            push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }

    S get(int p)
    {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--)
            push(p >> i);
        return d[p];
    }

    S prod(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r)
            return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--)
        {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }

        S sml = e(), smr = e();
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

    S all_prod() { return d[1]; }

    void apply(int p, F f)
    {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--)
            push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }
    void apply(int l, int r, F f)
    {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r)
            return;

        int lllll = l;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--)
        {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r)
            {
                // cout << l << " " << r << endl;

                if (l & 1)
                {
                    // cout << f.start + (d[r].l - lllll) * f.inc << 'i';
                    all_apply(l++, F{f.start + (d[l].l - lllll) * f.inc, f.inc});
                }
                if (r & 1)
                {
                    r--;
                    // cout << "r: " << r << ' ' << d[r].l << d[r].r << endl;
                    // cout << f.start + (d[r].l - lllll) * f.inc << 'i';
                    all_apply(r, F{f.start + (d[r].l - lllll) * f.inc, f.inc});
                }
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++)
        {
            if (((l >> i) << i) != l)
                update(l >> i);
            if (((r >> i) << i) != r)
                update((r - 1) >> i);
        }
    }

private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f)
    {
        d[k] = mapping(f, d[k]);
        if (k < size)
            lz[k] = composition(f, lz[k]);
    }
    void push(int k)
    {
        int newl = d[2 * k].l;
        int oldl = d[k].l;
        auto f = lz[k];

        F ans = F{f.start + (newl - oldl) * f.inc, f.inc};
        all_apply(2 * k, ans);

        newl = d[2 * k + 1].l;

        // cout << k << ' ' << newl << ' ' <<oldl << endl;
        ans = F{f.start + (newl - oldl) * f.inc, f.inc};
        all_apply(2 * k + 1, ans);
        lz[k] = id();
    }
};

struct S
{
    int sum, size, l, r;
};

S op(S a, S b)
{
    return S{a.sum + b.sum, a.size + b.size, min(a.l, b.l), max(a.r, b.r)};
}

S e()
{
    return S{0, 0, (int)1000000000, -1};
}

struct F
{
    int start, inc;
};

S mapping(F f, S x)
{
    return S{x.sum + f.start * x.size + f.inc * ((x.size * (x.size - 1)) / 2), x.size, x.l, x.r};
}

F composition(F f, F g)
{
    return F{f.start + g.start, f.inc + g.inc};
}

F id()
{
    return F{0, 0};
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<S> a(n);
    rep(i, 0, n)
    {
        a[i].sum = 0LL;
        a[i].size = 1;
        a[i].l = i;
        a[i].r = i;
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> st(a);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            int a, d;
            cin >> a >> d;

            st.apply(l, r, F{a, d});
        }
        else
        {
            int x;
            cin >> x;
            cout << st.get(x - 1).sum << "\n";
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