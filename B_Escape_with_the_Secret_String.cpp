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
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    vector <char> a = {'c', 'f', 'i'};

    rep (i, 0, n){

        if (s[i] == a[count]) continue;
        else {
            count++;
        
            if (count == 3 || s[i] != a[count]) {
                cout << "NO" << endl;
                return;            
            }

        }
    }

    if (count == 2) {
        cout << "YES" << endl;
        return;
    }
    else {
        cout << "NO" << endl;
        return;
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