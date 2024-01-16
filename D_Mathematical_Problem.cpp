// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define msi multiset<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

void solve()
{
    int n;
    cin >> n;

    // int mx = pow(10, n);

    // map<msi, vi> m;

    // for (int i = 1; i * i < mx; i++)
    // {
    //     if (i * i >= mx / 10)
    //     {

    //         int f = i * i;

    //         msi curr;

    //         while (f)
    //         {
    //             curr.insert(f % 10);
    //             f /= 10;
    //         }

    //         m[curr].push_back(i * i);
    //     }
    // }

    // for (auto i : m)
    // {
    //     if (i.second.size() >= n)
    //     {
    //         for (auto j : i.first)
    //         {
    //             cout << j << ' ';
    //         }
    //         cout << '-';
    //         for (auto j : i.second)
    //             cout << j << ' ';

    //         cout << endl;
        
    //         break;
    //     }
    // }

    if (n == 1){
        cout << 1 << endl;
        return;
    }

    vector <string> curr = {"169", "196", "961"};

    for (int i = 5; i <= n; i += 2){
        // for (auto i: curr) cout << i << ' ';

        for (auto &i: curr) i.push_back('0'), i.push_back('0');

        string a = "1";
        rep (_, 0, (i - 3)/2) a.push_back('0');
        a.push_back('6');
        rep (_, 0, (i - 3)/2) a.push_back('0');
        a.push_back('9');       

        curr.push_back(a);
        
        a = "9";
        rep (_, 0, (i - 3)/2) a.push_back('0');
        a.push_back('6');
        rep (_, 0, (i - 3)/2) a.push_back('0');
        a.push_back('1');       

        curr.push_back(a);
    }
    for (auto i: curr) cout << i << endl;

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