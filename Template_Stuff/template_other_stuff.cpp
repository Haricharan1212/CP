// Problem: C. Nastia and a Hidden Permutation
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h> //Blitztage
using namespace std;

// for loop macros
#define fo(i, n) for (int i = 0; i < n; i++)
#define foL(i, n) for (long long i = 0; i < n; i++)
#define foa(i, k, n) for (int i = k; i < n; i++)
#define fob(i, k, n) for (int i = k; i >= n; i--)
#define foaL(i, k, n) for (long long i = k; i < n; i++)
#define fobL(i, k, n) for (long long i = k; i >= n; i--)

constexpr int bits(int x)
{
    return x == 0 ? 0 : 31 - __builtin_clz(x);
}

// template -> AnandOza && bqi343 Github
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

#define sort_by(x, y) sort(all(x), [&](const auto &l, const auto &r) { return y; })

#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }

using ld = long double;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template <typename T>
void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T>
void ckmax(T &a, const T &b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input
{
    template <class T1, class T2>
    void re(pair<T1, T2> &p);
    template <class T>
    void re(vector<T> &a);
    template <class T, size_t SZ>
    void re(array<T, SZ> &a);

    template <class T>
    void re(T &x) { cin >> x; }
    void re(double &x)
    {
        string t;
        re(t);
        x = stod(t);
    }
    template <class Arg, class... Args>
    void re(Arg &first, Args &...rest)
    {
        re(first);
        re(rest...);
    }

    template <class T1, class T2>
    void re(pair<T1, T2> &p) { re(p.f, p.s); }
    template <class T>
    void re(vector<T> &a)
    {
        for (int i = 0; i < sz(a); i++)
            re(a[i]);
    }
    template <class T, size_t SZ>
    void re(array<T, SZ> &a)
    {
        for (int i = 0; i < SZ; i++)
            re(a[i]);
    }
}
using namespace __input;

namespace __output
{
    template <typename T>
    struct is_outputtable
    {
        template <typename C>
        static constexpr decltype(declval<ostream &>() << declval<const C &>(), bool()) test(int) { return true; }
        template <typename C>
        static constexpr bool test(...) { return false; }
        static constexpr bool value = test<T>(int());
    };
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_outputtable<T>::value, bool>::type>
    void pr(const T &x);

    template <class T, typename V = decltype(declval<ostream &>() << declval<const T &>())>
    void pr(const T &x) { cout << x; }
    template <class T1, class T2>
    void pr(const pair<T1, T2> &x);
    template <class Arg, class... Args>
    void pr(const Arg &first, const Args &...rest)
    {
        pr(first);
        pr(rest...);
    }

    template <class T, bool pretty = true>
    void prContain(const T &x)
    {
        if (pretty)
            pr("{");
        bool fst = 1;
        for (const auto &a : x)
            pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
        if (pretty)
            pr("}");
    }

    template <class T>
    void pc(const T &x)
    {
        prContain<T, false>(x);
        pr("\n");
    }
    template <class T1, class T2>
    void pr(const pair<T1, T2> &x) { pr("{", x.f, ", ", x.s, "}"); }
    template <class T, typename V, typename S>
    void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg>
    void ps(const Arg &first)
    {
        pr(first);
        ps();
    }
    template <class Arg, class... Args>
    void ps(const Arg &first, const Args &...rest)
    {
        pr(first, " ");
        ps(rest...);
    }
}
using namespace __output;

#define __pn(x) pr(#x, " = ")
#ifdef BlitzLocal
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush
#else
#define pd(...)
#endif

namespace __algorithm
{
    template <typename T>
    void dedup(vector<T> &v)
    {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    }
    template <typename T>
    typename vector<T>::const_iterator find(const vector<T> &v, const T &x)
    {
        auto it = lower_bound(all(v), x);
        return it != v.end() && *it == x ? it : v.end();
    }
    template <typename T>
    size_t index(const vector<T> &v, const T &x)
    {
        auto it = find(v, x);
        assert(it != v.end() && *it == x);
        return it - v.begin();
    }
    template <typename I>
    struct _reversed_struct
    {
        I &v_;
        explicit _reversed_struct(I &v) : v_{v} {}
        typename I::reverse_iterator begin() const { return v_.rbegin(); }
        typename I::reverse_iterator end() const { return v_.rend(); }
    };
    template <typename I>
    _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
}
using namespace __algorithm;

namespace __io
{
    void setIO()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout << setprecision(15);
    }
}
using namespace __io;

template <typename T_vector>
void outvec(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
        start = 0;
    if (end < 0)
        end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

// #define int long long

#define noo       \
    {             \
        ps("NO"); \
        return;   \
    }
#define yess       \
    {              \
        ps("YES"); \
        return;    \
    }

#define GOOGLE 0
const ld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll N = 2e5;
string s, t;

#define Multitests 1

int ask(int t, int i, int j, int x)
{
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    cout.flush();
    int p;
    cin >> p;
    return p;
}

void ans(vector<int> p)
{
    cout << "! ";
    pc(p);
    cout.flush();
}

void solve()
{
}

int32_t main()
{
    // sieve();
    setIO();
#if Multitests
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
#if GOOGLE
        cout << "Case #" << i + 1 << ": ";
#endif
        solve();
    }
#else
    solve();
#endif
    return 0;
}