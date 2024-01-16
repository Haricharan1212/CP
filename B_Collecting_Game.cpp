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


// 1 2 4 5 20
void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep (i, 0, n)
        cin >> a[i];

    vi b = a;
    sort(b.begin(), b.end());

    vi c = b;
    rep (i, 0, n - 1)
        c[i + 1] += c[i];

    vi ans(n);
    ans[n - 1] = n - 1;
    
    map <int, int> m;
    m[b[n - 1]] = n - 1;


    for (int i = n - 2; i >= 0; i--){
        if (c[i] >= b[i + 1]) ans[i] = ans[i + 1];
        else ans[i] = i;

        m[b[i]] = ans[i];
    }

    rep (i, 0, n){
        cout << m[a[i]] << " ";
    }
    cout << endl;

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