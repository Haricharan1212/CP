// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

void solve()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    si left, right;

    rep(i, 0, n - 1)
    {
        if (s[i] == '(' && s[i + 1] == '(')
        {
            left.insert(i);
        }
        else if (s[i] == ')' && s[i + 1] == ')')
        {
            right.insert(i);
        }
    }

    // for (auto i : left)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : right)
    //     cout << i << " ";
    // cout << endl;
    // cout << 'x' << endl;

    while (q--)
    {
        int x;
        cin >> x;
        x--;

        if (n % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        left.erase(x), left.erase(x - 1);
        right.erase(x), right.erase(x - 1);
        if (s[x] == '(')
            s[x] = ')';
        else
            s[x] = '(';

        if (x < n - 1 && s[x] == '(' && s[x + 1] == '(')
            left.insert(x);
        if (x > 0 && s[x] == '(' && s[x - 1] == '(')
            left.insert(x - 1);
        if (x < n - 1 && s[x] == ')' && s[x + 1] == ')')
            right.insert(x);
        if (x > 0 && s[x] == ')' && s[x - 1] == ')')
            right.insert(x - 1);

        // cout << s << endl;

        // for (auto i : left)
        //     cout << i << " ";
        // cout << endl;
        // for (auto i : right)
        //     cout << i << " ";
        // cout << endl;
        // cout << 'x' << endl;

        if (s[0] == ')' || s[n - 1] == '(')
            cout << "NO" << endl;
        else if (s[0] == '(' && left.size() == 0 && right.size() == 0)
            cout << "YES" << endl;
        else if (left.size() == 0 || right.size() == 0)
            cout << "NO" << endl;
        // else if (*left.begin() > *right.begin())
        //     cout << "NO" << endl;
        // else if (*left.rbegin() > *right.rbegin())
        //     cout << "NO" << endl;
        else if (*left.begin() < *right.begin() && *left.rbegin() < *right.rbegin())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
