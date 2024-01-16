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

    void modify(int p, T value)
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

struct Node{
    vi freq;
    
    Node(int a){
        freq.resize(41, 0LL);
        freq[a]++;
    }

    Node () {
        freq.resize(41, 0LL);
    }

    int count(){
        int ans = 0;
        rep(i, 1, 41){
            if(freq[i] > 0){
                ans++;
            }
        }
        return ans;
    
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector <Node> a(n);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[i] = Node(x);
    }

    auto op = [&](Node a, Node b) {
        Node res(0);
        rep(i, 1, 41) {
            res.freq[i] = a.freq[i] + b.freq[i];
        }
        return res;
    };

    segtree<Node> st(a, op, Node(0));

    while (q--) {

        int type;cin >> type;

        if (type == 1){
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.query(l, r).count() << "\n";
        }
        else {
            int i, x;
            cin >> i >> x;
            i--;
            st.modify(i, Node(x));        
        }

    }

}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
//    cin >> tc;
    while (tc--)
        solve();

    return 0;
}