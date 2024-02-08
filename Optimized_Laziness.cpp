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

int32_t main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep (i, 1, n) a[i] += a[i - 1];
    int q;
    cin >> q;
    while (q--){
        int k;
        cin >> k;
        cout << 86400-a[k - 1] << endl;
    }
}