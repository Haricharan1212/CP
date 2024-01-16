#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define int long long
// #define ld long double

void solve(int numberr)
{
    int n;
    cin >> n;
    int a[n];
    int freq[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // miz = min(miz,a[i]);
        freq[a[i]]++;
    }

    int num = 0;

    for (int i = 0; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] > i)
            {
                cnt++;
            }
        }
        if (cnt == i)
        {
            cout << cnt << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}