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

const int N = 10;

int tree[2 * N];
int n;
// function to build the tree
void build(vi arr)
{
    // insert leaf nodes in tree
    for (int i = 0; i < n; i++)
        tree[n + i] = arr[i];

    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
}

// function to update a tree node
// void updateTreeNode(int p, int value)
// {
//     // set value at position p
//     tree[p + n] = value;
//     p = p + n;

//     // move upward and update parents
//     for (int i = p; i > 1; i >>= 1)
//         tree[i >> 1] = tree[i] + tree[i ^ 1];
// }

// function to get sum on interval [l, r)
int query(int l, int r)
{
    int res = 1e9;

    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = min(res, tree[l++]);

        if (r & 1)
            res = min(res, tree[--r]);
    }

    return res;
}

void solve()
{
    cin >> n;

    vi a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, int> m;

    vi b = a;
    sort(b.begin(), b.end());

    rep(i, 0, n) m[b[i]] = i + 1;

    rep(i, 0, n) a[i] = m[a[i]];

    // rep (i, 0, n) cout << a[i] << ' ';
    // cout << endl;

    // rep (i, 0, n) t[n + i] = a[i];
    build(a);

    int ans = 0;

    vi c(n + 1);
    rep(i, 1, n + 1) c[a[i]] = i;

    // rep(gap, 2, n + 1)
    // {
    //     int cnt = 0;
    //     rep(start, 0, n - gap)
    //     {
    //         // int end = start + gap - 1;
    //         // unq.insert(query(start, end +1));

    //         int start1 = start;
    //         int start2 = start + 1;

    //         int end1 = start + gap - 1;
    //         int end2 = start + gap;

    //         // cout << query(start1, end1 + 1) << ' ' << query(start2, end2 + 1) << endl;

    //         if (a[start1] == query(start1, end1 + 1) && a[end2] == query(start2, end2 + 1))
    //         {
    //             cnt++;
    //             cout << start1 << ' ' << end1 << ' ' << start2 << ' ' << end2 << endl;
    //         }
    //     }

    //     ans += cnt;
    // }

    pi curseg = {n + 1, -1};
    ans = 0;

    rep(i, 1, n + 1)
    {
        int ind = c[i];
        cout << ind << ' ';
        curseg.first = min(curseg.first, ind);
        curseg.second = max(curseg.second, ind);

        int l = curseg.second - curseg.first + 1;

        cout << (curseg.first + 1) * (n - curseg.second) << '-';

        if (l == 1)
            ans += (l * (l - 1)) / 2 * (curseg.first) * (n - curseg.second - 1);

        cout << ans << ' ';
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}