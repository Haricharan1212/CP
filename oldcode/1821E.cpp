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

int ff(string ss)
{

    int count = 0;
    int ans = 0;
    rep(i, 0, ss.size())
    {
        if (ss[i] == '(')
            count++, ans += count - 1;
        else
            count--;
    }

    return ans;
}

string operate(string s)
{
    int count = 0;

    int n = s.size();

    int start = 0;

    int cstart = 0, cend = 0;
    int val = -1;

    rep(i, 0, n)
    {
        if (s[i] == '(')
            count++;
        else
            count--;

        if (count == 0)
        {
            string ss = s.substr(start, i - start + 1);
            int num = ff(ss);

            if (num > val)
            {
                val = num;
                cstart = start;
                cend = i;
            }
            start = i + 1;
        }
    }

    string ans;

    ans = s.substr(0, cstart) + s.substr(cstart + 1, cend - cstart - 1) + "()" + s.substr(cend + 1, n - cend - 1);

    return ans;
}

void solve()
{
    int k;
    cin >> k;

    string s;
    cin >> s;

    rep(i, 0, k)
    {
        s = operate(s);
        // cout << s << endl;
    }

    cout << ff(s) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
