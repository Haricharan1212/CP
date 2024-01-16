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

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<pair<int, int>> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= heights[i])
            st.pop();
        if (st.empty())
            right[i] = n - 1;
        else
            right[i] = st.top().second - 1;
        st.push({heights[i], i});
    }

    st = {};

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= heights[i])
            st.pop();
        if (st.empty())
            left[i] = 0;
        else
            left[i] = st.top().second + 1;
        st.push({heights[i], i});
    }

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(heights[i] * (right[i] - left[i] + 1), maxi);

    return maxi;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep (i, 0, n) cin >> a[i];

    cout << largestRectangleArea(a) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();

    return 0;
}