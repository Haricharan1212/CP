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

int f (int i, int curr){
    int ans = 0;
    int cnt = 0;
    
    while (i || curr){
            int r1 = curr % 10;
            int r2 = i % 10;

            curr /= 10;
            i /= 10;

            ans += ((int) powl (10, cnt)) * (((r1 ^ r2)) % 10);
            cnt++;
        }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int ans = n;

    for (int j = n - 1; j >= 1; j--){
        ans = f (j, ans);
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