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

    string t = s;

    int zer = count(s.begin(), s.end(), '0');
    int one = count(s.begin(), s.end(), '1');

    int n = s.size();

    int curr = 0;
    int ans = 0;

    set <int> ones, zers;

    rep (i, 0, n) {
        if (s[i] == '1') ones.insert(i);
        else zers.insert(i);
    }

    rep(i, 0, n)
    {
        // cout << s << ' ' << t << endl;
        // cout << zers.size() << ' ' << ones.size() << endl;

        // // if (zers.size())
        // // for (auto x: zers) cout << x << ' ';
        // // cout << endl;
        // // if (ones.size())
        // // for (auto x: ones) cout << x << ' ';
        // // cout << endl;

        // // if (t[i] == '1') one--, ones.pop_front();
        // // else zer--, zers.pop_front();

        // cout << curr << 'c';

        if (s[curr] == t[i])
        {
            if (s[curr] == '1' && zers.size()){
                swap (t[i], t[*zers.begin()]);
                ones.insert(*zers.begin());
                ones.erase(i);
                zers.erase(zers.begin());
                curr++;
            }
            else if (s[curr] == '0' && ones.size()){
                // cout << 'a' << endl;
                swap (t[i], t[*ones.begin()]);
                zers.insert(*ones.begin());
                zers.erase(i);
                ones.erase(ones.begin());
                curr++;
            }
            else ans++;
            
            continue;
        }

        else {
            curr++;
        if (t[i] == '1') one--, ones.erase(i);
        else zer--, zers.erase(i);
        }

    }

    cout << ans << endl;
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