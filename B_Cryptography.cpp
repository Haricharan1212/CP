// Haricharan
#include <bits/stdc++.h>
using namespace std;

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
    function <void(T&, T&)> op; //
    function <T(T, T&)> op2; //
    T nullval;

    segtree(vector<T> &arr, auto op, auto op2, T nullval)
    {
        // arr is the input array, op is the operation, null is the default element
        n = arr.size();
        this->op = op;
        this->op2 = op2;
        this->nullval = nullval;

        t.resize(2 * n, nullval);

        for (int i = 0; i < n; ++i)
            t[n + i] = arr[i];

        for (int i = n - 1; i > 0; --i)
            t[i] = op2(t[i << 1], t[i << 1 | 1]);
    }

    T query(int l, int r)
    {
        // minimum in range [l, r) (r is excluded), zero indexed
        T res1 = nullval, res2 = nullval;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                op(res1, t[l++]);
            if (r & 1)
                oprt(t[--r], res2);
        }

        op(res1, res2);
        return res1;
    }
};

int r;

struct Matrix
{
    vector<vector<int>> mat;

    Matrix()
    {
        mat.resize(2, vector<int>(2, 0));
    }

    void print()
    {
        cout << mat[0][0] << " " << mat[0][1] << "\n";
        cout << mat[1][0] << " " << mat[1][1] << "\n";
    }
};

void op(Matrix &a, Matrix &other)
{
    a.mat = {{(a.mat[0][0] * other.mat[0][0] + a.mat[0][1] * other.mat[1][0]) % r, (a.mat[0][0] * other.mat[0][1] + a.mat[0][1] * other.mat[1][1]) % r},
                   {(a.mat[1][0] * other.mat[0][0] + a.mat[1][1] * other.mat[1][0]) % r, (a.mat[1][0] * other.mat[0][1] + a.mat[1][1] * other.mat[1][1]) % r}};
}

void oprt(Matrix &a, Matrix &other)
{
    other.mat = {{(a.mat[0][0] * other.mat[0][0] + a.mat[0][1] * other.mat[1][0]) % r, (a.mat[0][0] * other.mat[0][1] + a.mat[0][1] * other.mat[1][1]) % r},
                   {(a.mat[1][0] * other.mat[0][0] + a.mat[1][1] * other.mat[1][0]) % r, (a.mat[1][0] * other.mat[0][1] + a.mat[1][1] * other.mat[1][1]) % r}};
}


Matrix op2(Matrix a, Matrix other)
{
    a.mat = {{(a.mat[0][0] * other.mat[0][0] + a.mat[0][1] * other.mat[1][0]) % r, (a.mat[0][0] * other.mat[0][1] + a.mat[0][1] * other.mat[1][1]) % r},
                   {(a.mat[1][0] * other.mat[0][0] + a.mat[1][1] * other.mat[1][0]) % r, (a.mat[1][0] * other.mat[0][1] + a.mat[1][1] * other.mat[1][1]) % r}};

    return a;
}


void solve()
{
    int n, m;
    cin >> r >> n >> m;

    vector<Matrix> a(n, Matrix());

    rep(i, 0, n)
    {
        rep(j, 0, 2)
        {
            rep(k, 0, 2)
            {
                cin >> a[i].mat[j][k];
            }
        }
    }

    Matrix identity = Matrix();
    identity.mat[0][0] = identity.mat[1][1] = 1;

    segtree<Matrix> st(a, op, op2, identity);

    rep(i, 0, m)
    {
        int l, k;
        cin >> l >> k;
        l--;

        Matrix ans = st.query(l, k);
        ans.print();
        cout << endl;
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