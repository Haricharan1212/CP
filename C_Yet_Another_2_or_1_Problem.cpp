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

    while (s.size() > 1 && k)
    {
        string t = s;
        reverse(t.begin(), t.end());

        vector <int> freq (26, 0);
        rep (i, 0, s.size()){        
            freq[s[i] - 'a']++;
        }

        int un = 0;
        rep (i, 0, 26){
            if (freq[i])
                un++;
        }

        if (un == 1) break;

        k--;
        if (s == t)
            s.push_back(s[s.size() - 1]);

        else
        {
            s = s.substr(0, s.size() / 2);
        }
    }

    while (k){
        s.push_back(s[s.size() - 1]);
        k--;
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