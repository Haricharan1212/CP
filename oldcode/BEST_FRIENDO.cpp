#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        string c;
        cin >> c;
        string d;
        cin >> d;

        int n = c.size();
        rep (i, 0, n) c[i] = tolower(c[i]);

        int m = d.size();
        rep (i, 0, m) d[i] = tolower(d[i]);

        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        if (c == d)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
   return 0;
}