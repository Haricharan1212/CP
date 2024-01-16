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

void solve()
{
    int n;
    cin >> n;

    vi a(n), b(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rep(i, 0, n)
    {
        cin >> b[i];
    }

    vector<pi> pieces, piecesnext;
    pieces.push_back({0, n - 1});

    // rep(i, 1, n + 1)
    // {
    //     // for (auto i : pieces)
    //     //     cout << i.first << "-" << i.second << ' ';
    //     // cout << endl;

    //     piecesnext = {};

    //     for (int j = 0; j < pieces.size(); j++)
    //     {
    //         int l = pieces[j].first, r = pieces[j].second;
    //         si curr;

    //         for (int k = l; k <= r; k++)
    //         {
    //             if (a[k] == i)
    //             {
    //                 curr.insert(k);
    //             }
    //         }

    //         map <int, bool> poss;

    //         for (auto pt: curr){

    //             int f = pt;

    //             while (f <= r && a[f] <= i){
    //                 poss[f] = 1;
    //                 f++;
    //             }

    //             f = pt;

    //             while (f >= l && a[f] <= i){
    //                 poss[f] = 1;
    //                 f--;
    //                 if (poss[f]) break;
    //             }
    //         }

    //         int start = l;

    //         for (int k = l; k <= r; k++)
    //         {
    //             if (b[k] == i)
    //             {
    //                 if (!poss[k]) {
    //                     cout << "NO" << endl;
    //                     return;
    //                 }
    //                 else {
    //                     piecesnext.push_back({start, k - 1});
    //                     start = k + 1;
    //                 }
    //             }
    //         }

    //         piecesnext.push_back({start, r});
    //     }

    //     pieces = {};

    //     for (auto j : piecesnext)
    //         if (j.first <= j.second)
    //             pieces.push_back(j);
    // }

    // cout << "YES" << endl;



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