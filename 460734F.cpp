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
    int n, x;
    cin >> n >> x;

    vi sum(n), ssum(n), ors(n);
    si R, A;
    rep(i, 0, n)
    {
        cin >> sum[i];
    }
    int curr = 0;
    A.insert(curr);
    rep(i, 0, n)
    {
        cin >> ssum[i];
        curr += ssum[i];
        A.insert(curr);
    }

    curr = 0;
    R.insert(0);
    rep(i, 0, n)
    {
        cin >> ors[i];
        curr |= ors[i];
        R.insert(curr);
    }

    curr = 0;
    sum.push_back(0);
    rep(i, 0, n + 1)
    {
        int des = x - curr;
        int desr = des | curr;
        if (A.find(des) != A.end() && R.find(desr) != R.end())
        {
            cout << "yes\n";
            return;
        }
        curr += sum[i];
    }

    cout << "no" << endl;
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
