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

int count_digits(int number)
{
    return (int)log10(number) + 1;
}

map<vi, vi> m;

void solve()
{

    int A, B, C, k;
    cin >> A >> B >> C >> k;

    if (max(A, B) + 1 < C || C < (max(A, B)))
    {
        cout << -1 << endl;
        return;
    }

    int aa = pow(10, A - 1);
    int bb = pow(10, B - 1);
    int cc = pow(10, C - 1);

    if (C == max(A, B))
    {
        for (auto i : m[{A, B, C}])
        {
            if (i < k)
                cout << i << ' ';
        }

        int pos = lower_bound(m[{A, B, C}].begin(), m[{A, B, C}].end(), k) - m[{A, B, C}].begin();

        pos--;
        int num = k - m[{A, B, C}][pos] - 1;

        aa += pos;
        bb += num;

        cc = aa + bb;

        if (count_digits(aa) != A || count_digits(bb) != B || count_digits(cc) != C)
        {
            cout << -1 << endl;
            return;
        }

        cout << aa << " + " << bb << " = " << cc << endl;
        return;
    }

    if (C == max(A, B) + 1)
    {
        // for (auto i : m[{A, B, C}])
        // {
        //     if (i < k)
        //         cout << i << ' ';
        // }

        int pos = lower_bound(m[{A, B, C}].begin(), m[{A, B, C}].end(), k) - m[{A, B, C}].begin();
        pos--;

        if (pos == m[{A, B, C}].size() - 1)
        {
            cout << -1 << endl;
            return;
        }

        int num = m[{A, B, C}][pos + 1] - k + 1;

        aa += pos;
        bb = cc - num;
        cc = aa + bb;

        if (count_digits(aa) != A || count_digits(bb) != B || count_digits(cc) != C)
        {
            cout << -1 << endl;
            return;
        }

        cout << aa << " + " << bb << " = " << cc << endl;
        return;
    }
    cout << -1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    int cnt = 0;
    rep(i, 1, 7)
        rep(j, 1, 7)
            rep(k, 1, 7)
    {
        if (k < max(i, j) || k > (max(i, j) + 1))
            continue;

        int aa = pow(10, i - 1);
        int bb = pow(10, j - 1);
        int cc = pow(10, k - 1);
        int aaa = aa;

        int kk = 0;

        int mx = 1e9;

        if (k == max(i, j))
            while (true)
            {
                cnt++;
                m[{i, j, k}].push_back(kk);
                kk += cc * 10 - aa - (bb);
                aa++;

                if (kk > mx || aa == aaa * 11)
                    break;
            }
        else
        {
            while (true)
            {
                m[{i, j, k}].push_back(kk);

                kk += aa;
                aa++;

                if (kk > mx || aa == aaa * 11)
                    break;
            }
        }
    }

    while (tc--)
        solve();

    return 0;
}
