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

const int N = 2e5 + 5; // limit for array size
int n;
const int mn = 0;
int t[2 * N];
 
void build()
{ 
    for (int i = n - 1; i > 0; --i)
        t[i] = max(t[i << 1], t[i << 1 | 1]);
}
void modify(int p, int value)
{ // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = max(t[p], t[p ^ 1]);
}
int query(int l, int r)
{ // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, t[l++]);
        if (r & 1)
            res = max(res, t[--r]);
    }
    return res;
} // cin inputs from index t + n + i, then build, then modify


const int mx = 1e9 + 5;
int tt[2 * N];
void build2()
{ 
    for (int i = n - 1; i > 0; --i)
        tt[i] = min(tt[i << 1], tt[i << 1 | 1]);
}
void modify2(int p, int value)
{ // set value at position p
    for (tt[p += n] = value; p > 1; p >>= 1)
        tt[p >> 1] = min(tt[p], tt[p ^ 1]);
}
int query2(int l, int r)
{ // sum on interval [l, r)
    int res = mx;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = min(res, tt[l++]);
        if (r & 1)
            res = min(res, tt[--r]);
    }
    return res;
} // cin inputs from index t + n + i, then build, then modify


void solve()
{
    cin >> n;

    for (int i = 0; i < 2 * n; i++)
        t[i] = mn, tt[i] = mx;

    vi a(n), b(n);
    map <int, vi> aa, bb;

    rep(i, 0, n)
    {
        cin >> a[i];
        t[n + i] = a[i];
        tt[n + i] = a[i];
        aa[a[i]].push_back(i);
    }

    build();
    build2();

    rep(i, 0, n)
    {
        cin >> b[i];
        bb[b[i]].push_back(i);
    }

    rep (i, 1, n + 1){

        if (bb.find(i) == bb.end()) continue;

        for (auto j: bb[i]){

            if (aa.find(i) == aa.end()) {
                cout << "NO" << endl;
                return;
            }

            bool poss = false;
            auto it = lower_bound(aa[i].begin(), aa[i].end(), j);

            if (it != aa[i].end()){
                if (query(j + 1, *it + 1) <= i && query2(j + 1, *it + 1) >= i){
                    poss = true;
                }
            }

            it = upper_bound(aa[i].begin(), aa[i].end(), j);

            if (it != aa[i].begin()){                
                if (query(*(--it), j) <= i && query2(*(--it), j) >= i){
                    poss = true;
                }
            }

            // cout << 1 << endl;
            // return;

            if (!poss){
                cout << "NO" << endl;
                return;
            }
            else{
                modify(j, i);
                modify2(j, i);
            }
        }

    }

    cout << "YES" << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}