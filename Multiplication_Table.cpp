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

bool check (int n, int mid){
    int count = 0;
    for(int i = 1; i <= n; i++){
        count += min(mid/i, n);
    }
    return count >= (n*n+1)/2;
}

void solve()
{
    int n;
    cin >> n;

    int l = 0, r = n * n;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (check(n, mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << "\n";
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