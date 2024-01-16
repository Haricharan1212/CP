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
set<char> poss = {'+', 'X', 'O'};

void solve()
{
    string arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    for (int i = 0; i < 3; i++)
    {
        for (auto c : poss)
        {
            int cnt = 0;
            for (int j = 0; j < 3; j++)
                if (arr[i][j] == c)
                    cnt++;

            if (cnt == 3)
            {
                cout << c << endl;
                return;
            }
        }
    }

    rep(j, 0, 3)
    {
        for (auto c : poss)
        {
            int cnt = 0;
            for (int i = 0; i < 3; i++)
                if (arr[i][j] == c)
                    cnt++;

            if (cnt == 3)
            {
                cout << c << endl;
                return;
            }
        }
    }

    for (auto c : poss)
    {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            if (arr[i][i] == c)
                cnt++;

        if (cnt == 3)
        {
            cout << c << endl;
            return;
        }
    }

    for (auto c : poss)
    {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            if (arr[i][2 - i] == c)
                cnt++;

        if (cnt == 3)
        {
            cout << c << endl;
            return;
        }
    }

    cout << "DRAW" << endl;
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
