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

si getprimefactors (int n){
    si ans;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            ans.insert(i);
            while (n % i == 0){
                n /= i;
            }
        }
    }

    if (n > 1){
        ans.insert(n);
    }

    return ans;

}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep (i, 0, n)
    {
        cin >> a[i];
    }

    si primes = getprimefactors(n);

    map <int, vi> m;
    for (auto &i: primes){
        m[i] = a;
        for (auto &j: m[i]){
                j %= i;
            }
        }
    
    int ans = 0;

    


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