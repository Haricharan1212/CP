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
    int n;
    cin >> n;


    int largest = sqrt(n);
    while (largest * largest > n) n--;

    int div = n / largest;    
    int rem = n - largest * div;

    int ans = 0;

    for (int i = 1; i <= largest; i++){
        ans += max(0LL, (div - i) * (largest - i));
    }

    largest = (rem == 0? 0: (rem - 1));
    ans += (largest * (largest + 1))/2;

    cout << ans << endl;
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