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

#define float long double

pi check (vi &a, int n, float mid){

    float sum = 0;
    float min_sum = 0;
    float max_sum = 0;

    float min_prefix = 0;
    float prefix = 0;

    int min_prefix_index = -1;
    int prefix_index = -1;

    rep (i, 0, n){
        sum += a[i] - mid;

        if (sum - min_sum > 0){
            min_sum = sum;
            min_prefix_index = prefix_index;
        }

        if (sum - max_sum < 0){
            max_sum = sum;
            prefix_index = i;
        }
    }

    return {min_prefix_index, prefix_index};
}

void solve()
{
    int n, d;
    cin >> n >> d;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int ans = 0;

    float l = 0;
    float r = 101;

    while (l < r){

        float mid = (l + r) / 2;

        pi num = check (a, n, mid);

        if (num.first != -1){
            ans = max(ans, num.second - num.first);
        }
    }


    cout << ans << "\n";
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