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

// lower bound for reversed sorted array
// lower_bound (vector.begin(), vector.end(), num, greater<int>())

bool check (int n, vi a, int mid, int k){

    int curr = 0;
    int need = 0;
    while (a.size())  {
        int num = mid - curr;
        auto pt = lower_bound(a.begin(), a.end(), num, greater<int>());

        if (curr == 0 && pt == a.end()) {
            need = 1e9;
            break;
        }

        if (pt == a.end()){
            need++;
            curr = 0;
        }
        else{
            curr+= *pt;
            a.erase(pt);
        }
    }

    if (curr) need++;

    
    if (need <= k) return true;
    else return false;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep (i, 0, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int l = 0, r = 1e9;

    while (l < r){
        int mid = (l + r) / 2;

        if (check (n, a, mid, k))
            r = mid;
        else
            l = mid + 1;
    }


    cout << l << endl;
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