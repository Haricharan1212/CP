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
#define ll long long

// 3 2 2 4 5

void solve()
{

        ll n;
        cin >> n;
        ll arr[n + 1], brr[n + 1];
        brr[0] = LLONG_MIN;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            brr[i] = arr[i];
        }
        sort(brr, brr + (n + 1));
        ll ptr = 1;
        bool chk = true;
        ll op = 0;
        while (ptr != ((n + 1) / 2) + 1)
        {
            if(n%2==1&&ptr==(n+1)/2)
            {
                if(arr[ptr]!=brr[n+1-ptr])
                {
                    chk=false;
                    break;
                }
                ++ptr;
                continue;
            }
            if ((arr[ptr] == brr[ptr] && arr[n + 1 - ptr] == brr[n + 1 - ptr]))
            {
                if (op % 2 == 1)
                    op++;
            }
            else if (arr[ptr] == brr[n + 1 - ptr] && arr[n + 1 - ptr] == brr[ptr])
            {
                if (op % 2 == 0)
                    op++;
            }
            else
            {
                chk = false;
                break;
            }
            ++ptr;
        }
        if (chk)
        {
            cout << op << endl;
        }
        else
            cout << "-1\n";

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