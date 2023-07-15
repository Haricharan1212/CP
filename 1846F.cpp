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

int check(int arr[10], int arr2[10])
{
    rep(i, 0, 10) if (arr[i] < arr2[i]) return i;
    return -1;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) cin >> a[i];
    if (n == 1)
    {
        cout << "! 1" << endl;
    }

    int freq[10] = {0}, freqq[10] = {0};
    rep(i, 0, n) freq[a[i]]++;

    cout << "- 0" << endl;
    cout.flush();
    vi b(n);

    rep(i, 0, n) cin >> b[i], freqq[b[i]]++;
    int mmnum = check(freq, freqq);
    if (mmnum == -1)
    {
        int freqqq[10] = {0};
        cout << "- 0" << endl;
        cout.flush();

        rep(i, 0, n) cin >> b[i], freqqq[b[i]]++;

        mmnum = check(freqq, freqqq);
        rep(i, 0, 10) freqq[i] = freqqq[i];
    }

    rep(i, 0, 10) if (i != mmnum) freqq[i] = 0;

    vi out;
    rep(i, 0, n) if (b[i] == mmnum) continue;
    else out.push_back(i + 1);

    cout << "- " << out.size() << ' ';
    for (auto i : out)
        cout << i << ' ';
    cout << endl;
    cout.flush();

    vi curr(n - out.size());
    rep(i, 0, curr.size()) cin >> curr[i];

    int freqqqq[10] = {0};
    rep(i, 0, curr.size()) freqqqq[curr[i]]++;

    mmnum = check(freqq, freqqqq);
    if (mmnum == -1)
    {
        int freqqqqq[10] = {0};
        cout << "- 0" << endl;
        cout.flush();

        rep(i, 0, curr.size()) cin >> curr[i], freqqqqq[curr[i]]++;

        mmnum = check(freqqqq, freqqqqq);
    }

    rep(i, 0, n) if (curr[i] == mmnum)
    {
        cout << "! " << i + 1 << endl;
        return;
    }

    cout << "WA" << endl;
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
