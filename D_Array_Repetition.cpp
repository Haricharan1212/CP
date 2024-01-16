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
    int n, q;
    cin >> n >> q;

    vi ops;

    int size = 0;

    while (n--){
        int type;
        cin >> type;
        int x;
        cin >> x;

        if (size > (int)1e18){
            continue;
        }

        if (type == 1){
            size++;
        }
        else{
            if (size > ((int)1e18)/(x + 1))
                size = 1e18;

            size *= (x + 1);
        }

    }

    while (q--){
        int k;
        cin >> k;

        
    }


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