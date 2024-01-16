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

    template <bool (*f)(S)>
    int max_right(int l) const
    {
        return max_right(l, [](S x)
                         { return f(x); });
    }
    template <class F>
    int max_right(int l, F f) const
    {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n)
            return _n;
        l += size;
        S sm = e();
        do
        {
            while (l % 2 == 0)
                l >>= 1;
            if (!f(op(sm, d[l])))
            {
                while (l < size)
                {
                    l = (2 * l);
                    if (f(op(sm, d[l])))
                    {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)>
    int min_left(int r) const
    {
        return min_left(r, [](S x)
                        { return f(x); });
    }
    template <class F>
    int min_left(int r, F f) const
    {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0)
            return 0;
        r += size;
        S sm = e();
        do
        {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!f(op(d[r], sm)))
            {
                while (r < size)
                {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm)))
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

struct S {
    int sum, pref;
};

S op (S a, S b){
    return S{a.sum + b.sum, max(a.pref, a.sum + b.pref)};
}

S e(){
    return S{0, 0};
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector <S> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].sum;
        a[i].pref = max(0LL, a[i].sum);
    }

    segtree<S, op, e> st(a);   

    while (q--){
        int type;
        cin >> type;

        if (type == 1){
            int i, x;
            cin >> i >> x;
            i--;
            st.set(i, S{x, max(0LL, x)});
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.prod(l, r).pref << "\n";
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