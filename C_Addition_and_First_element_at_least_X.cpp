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
                if (l & 1)
                    all_apply(l++, f);
                if (r & 1)
                    all_apply(--r, f);
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

    template <bool (*g)(S)>
    int min_left(int r)
    {
        return min_left(r, [](S x)
                        { return g(x); });
    }
    template <class G>
    int min_left(int r, G g)
    {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0)
            return 0;
        r += size;
        for (int i = log; i >= 1; i--)
            push((r - 1) >> i);
        S sm = e();
        do
        {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!g(op(d[r], sm)))
            {
                while (r < size)
                {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm)))
                    {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
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
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

using S = int;

struct F
{
    int a, b;
};

S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F l, S r) { return r * l.a + l.b; }
F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }
F id() { return F{1, 0}; }

// + a, + a + d, + a + 2d... a + (n - 1)d
// + a, + d, +d, +d ... d, -(a + (n - 1)d)

void solve()
{
    int n, q;
    cin >> n >> q;

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i, 0, n) seg.set(i, 0);

    while (q--)
    {
        int type;
        cin >> type;

        // rep(i, 0, n) cout << seg.get(i) << ' ';
        // cout << endl;

        // cout << seg.prod(0, 3) << 'l';

        if (type == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            seg.apply(l, r, {1, val});
        }
        else
        {
            int l, x;
            cin >> x >> l;
            int r = n;

            if (seg.prod(l, r) < x){
                cout << -1 << endl;
                continue;
            }

            while (l + 1 < r && l < n)
            {
                int mid = (l + r)/2;

                // cout << l << '-' << r << ' ';

                if (seg.prod(l, mid) >= x)
                    r = mid;
                else
                    l = mid;                

            }

            cout << l << endl;
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