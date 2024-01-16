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

int op (int x,  int y){return __gcd(x, y);}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep (i, 0, n) cin >> a[i];

    segtree <int> st (a, op, 0LL);

    int l = 0;
    int ans = 10000000;

    rep (r, 0, n){

        int num = st.query(l, r + 1);

        if (num != 1) continue;

        while (st.query(l + 1, r + 1) == 1){
            l++;
        }

        // cout << l << '-' << r << endl;

        ans = min(ans, r - l + 1);
    }

    if (ans == 10000000) ans = -1;

    cout << ans << endl;

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