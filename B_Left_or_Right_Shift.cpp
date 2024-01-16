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

    string s;
    cin >> s;

    rep (i, 0, n){
        char c = s[i];

        if (c <= 'n'){
            int reqd = c - 'a';
            if (k > reqd) {
                k -= reqd;
                s[i] = 'a';
            }
            else{
                s[i] = c - k;
                k = 0;
                break;
            }

        }
        else{
            int reqd = 'z' - c + 1;
            if (k >= reqd) {
                k -= reqd;
                s[i] = 'a';
            }
            else{
                s[i] = c + k;
                k = 0;
                break;
            }

        }
    }

    if (k > 0 && k%2){
        s[n - 1] = 'b';
    }

    cout << s << endl;
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