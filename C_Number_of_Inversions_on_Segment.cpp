// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define rep(var, l, r) for (long long var = l; var < r; var++)

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
};

struct Node
{

    vector<long long> count;
    long long inversions;

    Node()
    {
        count.resize(40, 0LL);
        inversions = 0;
    }
};

Node op(Node a, Node b)
{

    Node res = Node();

    for (long long i = 0; i < 40; i++)
    {
        res.count[i] = a.count[i] + b.count[i];
    }

    res.inversions = a.inversions + b.inversions;

    for (long long i = 39; i >= 0; i--)
    {
        for (long long j = 0; j < i; j++)
        {
            res.inversions += 1LL * a.count[i] * b.count[j];
        }
    }

    return res;
}

void solve()
{
    long long n, q;
    cin >> n >> q;

    vector<Node> arr(n);

    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        x--;
        arr[i].count[x]++;
    }

    segtree<Node> st(arr, op, Node());

    // for (auto i: st.t) cout << i.inversions << ' ';

    while (q--)
    {
        long long type;
        cin >> type;

        if (type == 1)
        {
            long long l, r;
            cin >> l >> r;
            l--;

            cout << st.query(l, r).inversions << endl;
        }
        else
        {
            long long i, x;
            cin >> i >> x;
            x--;
            i--;
            Node f = Node();
            f.count[x]++;

            st.modify(i, f);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    long long tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}