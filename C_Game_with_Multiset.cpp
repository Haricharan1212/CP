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
    int m;
    cin >> m;

    vi arr (31, 0);

    rep (_, 0, m){
        int x;
        cin >> x;

        if (x == 1){
            int y;
            cin >> y;
            arr[y]++;

        }
        else{
            int f;
            cin >> f;

            int curr = 0;

            vi cp = arr;
            int flag = 1;

            while (f){
                if (f%2){
                    if (cp[curr] == 0) {
                        flag = 0;
                    }
                    else cp[curr]--;
                }

                cp[curr + 1] += cp[curr]/2;
                curr++;
            
                f /= 2;
            }

            cout << (flag ? "YES" : "NO") << endl;
        }


    }

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