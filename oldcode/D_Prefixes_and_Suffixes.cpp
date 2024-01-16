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

    vector<string> s;

    string ans1, ans2;

    rep(i, 0, 2 * n - 2)
    {
        string temp;
        cin >> temp;
        s.push_back(temp);

        if (temp.size() == n - 1)
        {
            if (ans1.size() == 0)
                ans1 = temp;
            else
                ans2 = temp;
        }
    }

    string ans;
    if (ans1.substr(0, n - 2) == ans2.substr(1, n - 2))
    {
        ans = ans2[0] + ans1;
    }
    else if (ans1.substr(1, n - 2) == ans2.substr(0, n - 2))
    {
        ans = ans1 + ans2[n - 2];
    }

    // cout << ans;

    vector<int> flag(n - 1, 0);

    rep(i, 0, 2 * n - 2)
    {
        if (s[i] == ans.substr(0, s[i].size()) && s[i] == ans.substr(1, s[i].size())){

            if (flag[s[i].size()] == 0){
                cout << "P";
                flag[s[i].size()] = 1;
            }
            else{
                cout << "S";
            }
        }

        else if (s[i] == ans.substr(0, s[i].size()))
        {
            cout << "P";
        }
        else
            cout << "S";
    }
    cout << endl;
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