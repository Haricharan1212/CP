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

auto precomp(int n)
{
    vector<map<pi, si>> a(n + 1);

    a[2] = {{{0, 0}, {0, 4}}, {{1, 1}, {2}}};

    rep(i, 3, n)
    {
        rep(j, 0, 2)
        {
            rep(k, 0, 2)
            {
                rep(l, 0, 2)
                {
                    int rowsum = (k * (i - 1) + l) % 2;
                    int colsum = (j * (i - 1) + l) % 2;

                    pi ind = {(rowsum + j + 2) % 2, (colsum + k + 2) % 2};

                    // rep(m, 0, a[i - 1][ind].size())
                    for (auto it : a[i - 1][ind])
                    {
                        a[i][{rowsum, colsum}].insert(it + k * (i - 1) + j * (i - 1) + l);
                    }
                    // a[i][{rowsum, colsum}] = a[i - 1][];
                }
            }
        }
    }

    // print a
    rep(i, 2, n)
    {
        cout << "i = " << i << endl;
        rep(j, 0, 2)
        {
            rep(k, 0, 2)
            {
                cout << "j = " << j << " k = " << k << endl;

                int num = a[i][{j, k}].size();
                // rep(l, 0, num)
                for (auto it : a[i][{j, k}])
                {
                    cout << it << " ";
                }
                cout << endl;
            }
        }
    }

    return a;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    if (n == 2 && k == 2){
        cout << "Yes" << endl;
        
        cout << "0 1\n1 0\n";

        return ;
    }

    if (n % 2 == 0)
    {
        if (k == 2 || k == n * n - 2 || k % 2)
        {
            cout << "No" << endl;
            return;
        }

        cout << "Yes" << endl;

        int flag = 1;
        if (k > n * n / 2)
        {
            flag = 0;
            k = n * n - k;
        }

        vii a(n, vi(n, 1 - flag));
        {
            int i = 0, j = 0;

            while (k)
            {
                if (k == 6)
                {
                    // if (n > 6)
                    {
                        i = n - 3;
                        j = n - 3;
                    }

                    a[i][j] = flag;
                    a[i][j + 1] = flag;
                    a[i + 1][j] = flag;
                    a[i + 1][j + 2] = flag;
                    a[i + 2][j + 1] = flag;
                    a[i + 2][j + 2] = flag;

                    k -= 6;
                }
                else
                {
                    a[i][j] = flag;
                    a[i][j + 1] = flag;
                    a[i + 1][j] = flag;
                    a[i + 1][j + 1] = flag;
                    k -= 4;
                }

                j += 2;

                if (j >= n - 1)
                {
                    j = 0;
                    i += 2;
                }
            }
        }

        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }

        return;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    // precomp(10);

    while (tc--)
        solve();

    return 0;
}