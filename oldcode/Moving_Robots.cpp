// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

#define float long double

vector<vector<float>> matrix_product(vector<vector<float>> &a, vector<vector<float>> &b)
{
    int n = a.size();
    vector<vector<float>> res(n, vector<float>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

vector<vector<float>> matrix_exp(vector<vector<float>> a, int b)
{
    int n = a.size();
    vector<vector<float>> res(n, vector<float>(n, 0));

    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }

    while (b)
    {
        if (b & 1)
            res = matrix_product(res, a);
        a = matrix_product(a, a);
        b >>= 1;
    }

    return res;
}

void solve()
{
    int k;
    cin >> k;

    int n = 64;

    vector<vector<float>> matr(n, vector<float>(n, 0));

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            vector<int> x = {0, 0, 1, -1};
            vector<int> y = {1, -1, 0, 0};

            int cnt = 0;

            for (int k = 0; k < 4; k++)
            {
                int newx = i + x[k];
                int newy = j + y[k];
                if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8)
                {
                    cnt++;
                }
            }

            for (int k = 0; k < 4; k++)
            {
                int newx = i + x[k];
                int newy = j + y[k];
                if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8)
                {
                    matr[i * 8 + j][newx * 8 + newy] = 1.0 / cnt;
                }
            }
        }
    }

    vector<vector<float>> ans = matrix_exp(matr, k);

    // cout << ans[0][1] << ' ';

    float anss = 0;

    rep(i, 0, n)
    {
        float ans1 = 1;

        rep(j, 0, n) ans1 *= ((long double)1 - ans[j][i]);

        anss = anss + ans1;
    }

    cout << fixed << setprecision(6) << anss << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}