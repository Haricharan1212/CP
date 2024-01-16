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
    string s;
    cin >> s;

    int n = s.size();

    int end = -1;

    rep (i, 1, n) {
        if (s[i] != '0') {
            end = i;
            break;
        }
    }

    if (end == -1){
        cout << -1 << endl;
        return;
    }

    int a = stoi(s.substr(0, end));
    int b = stoi(s.substr(end, n - end));

 
    if (a < b)
        cout << a << ' ' << b << endl;
    else
        cout << -1 << endl;

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