/**
    Lost Arrow (Aryan V S)
    Saturday 2020-10-10
**/

#include "bits/stdc++.h"

using namespace std;

struct node {
    int64_t inv = 0;
    vector <int> freq = vector <int> (40, 0);

    void combine (const node& l, const node& r) {
        inv = l.inv + r.inv;
        for (int i = 39; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                // frequency of bigger numbers in the left * frequency of smaller numbers on the right
                inv += 1LL * l.freq [i] * r.freq [j];
            }
            freq [i] = l.freq [i] + r.freq [i];
        }
    }
};

void build (vector <node>& tree, vector <int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        tree [v].inv = 0;
        tree [v].freq [a [tl]] = 1;
    }
    else {
        int tm = (tl + tr) / 2;
        build(tree, a, 2 * v + 1, tl, tm);
        build(tree, a, 2 * v + 2, tm + 1, tr);
        tree [v].combine(tree [2 * v + 1], tree [2 * v + 2]);
    }
}

void update (vector <node>& tree, int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree [v].inv = 0;
        tree [v].freq = vector <int> (40, 0);
        tree [v].freq [val] = 1;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(tree, 2 * v + 1, tl, tm, pos, val);
        else
            update(tree, 2 * v + 2, tm + 1, tr, pos, val);
        tree [v].combine(tree [2 * v + 1], tree [2 * v + 2]);
    }
}

node inv_cnt (vector <node>& tree, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return node();
    if (tl == l && tr == r)
        return tree [v];
    int tm = (tl + tr) / 2;
    node result;
    result.combine(inv_cnt(tree, 2 * v + 1, tl, tm, l, min(r, tm)), inv_cnt(tree, 2 * v + 2, tm + 1, tr, max(l, tm + 1), r));
    return result;
}

void solve () {
    int n, q;
    cin >> n >> q;
    vector <int> a (n);
    for (int i = 0; i < n; ++i) {
        cin >> a [i];
        --a [i];
    }

    vector <node> tree (4 * n);
    build(tree, a, 0, 0, n - 1);

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        --x; --y;

        if (type == 1) {
            node result = inv_cnt(tree, 0, 0, n - 1, x, y);
            cout << result.inv << '\n';
        }
        else if (type == 2) {
            update(tree, 0, 0, n - 1, x, y);
        }
        else
            assert(false);
    }
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(10);
    std::cout << std::fixed << std::boolalpha;

    int t = 1;
//  std::cin >> t;
    while (t--)
        solve();

    return 0;
}