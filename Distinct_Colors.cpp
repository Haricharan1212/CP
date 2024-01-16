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

void dfs (int node, vii &adj, vi &in, vi &out, vi &ord, int parent, int &time){

    ord[time] = node;
    in[node] = time;
    time++;

    for (int child: adj[node]){

        if (parent != child) {
            dfs (child, adj, in, out, ord, node, time);
        }
    }

    out[node] = time - 1;
}

void solve()
{
    int n;
    cin >> n;

    vi cols(n);
    rep (i, 0, n) cin >> cols[i];

    vii adj(n);
    rep (i, 0, n - 1){
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi in(n), out(n), ord(n);
    int time = 0;

    dfs (0, adj, in, out, ord, -1, time);

    // for (auto i: ord) cout << i << ' ';
    // cout << endl;

    // for (int i = 0; i < n; i++){
    //     cout << in[i] << ' ' << out[i] << endl;
    // }

    vi new_cols (n);

    rep (i, 0, n){
        new_cols[i] = cols[ord[i]];
    }

    // for (auto i: new_cols) cout << i << ' ';
    // cout << endl;
    

    rep (i, 0, n){

        int a = in[i];
        int b = out[i];

        si s;

        rep (i, a, b + 1) s.insert(new_cols[i]);

        cout << s.size() << ' ';

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