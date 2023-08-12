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
    int n, k;
    cin >> n >> k;

    vi a(k);
    rep(i, 0, k)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int num = 1 << k;

    int ans = 0;

    rep(i, 1, num)
    {
        bitset<20> nums(i);
        int current = 1;
        int flag = false;
        int cnt = 0;

        for (int j = 0; j < k; j++)
        {
            if (nums[j])
            {
                if (current > n / a[j])
                {
                    flag = true;
                    break;
                }

                current *= a[j], cnt++;
            }
        }

        if (flag)
            continue;

        if (cnt % 2 == 0) // even
            ans -= n / current;
        else
            ans += n / current;

        // cout << ans << ' ';
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
