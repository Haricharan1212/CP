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

struct Vertex
{
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};

Vertex *build(int a[], int tl, int tr)
{
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}

int get_sum(Vertex *v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm)) + get_sum(v->r, tm + 1, tr, max(l, tm + 1), r);
}

Vertex *update(Vertex *v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
}

void solve()
{
    int n, q;
    cin >> n >> q;

    int a[n];
    rep(i, 0, n) cin >> a[i];

    Vertex *roots[q + 1];
    roots[1] = build(a, 0, n - 1);

    int t = 1;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int k, a, x;
            cin >> k >> a >> x;

           // update(Vertex* v, int tl, int tr, int pos, int new_val) 

            roots[k] = update(roots[k], 0, n - 1, a - 1, x);
        }
        else if (type == 2)
        {
            int k, l, r;
            cin >> k >> l >> r;

            cout << get_sum(roots[k], 0, n - 1, l - 1, r - 1) << "\n";
        }   
        else
        {
            t++;
            int k;
            cin >> k;
            roots[t] = roots[k];
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