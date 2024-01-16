// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

const int N = 1e5 + 5;
bool prime[N + 1];

void sieve()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

void solve()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    int arr[26][26] = {0};

    for (int i = 3; i < n; i++)
    {
        if (s[i] == s[i - 1] && s[i] == s[i - 2] && s[i] == s[i - 3])
        {
            cout << "YES" << endl;
            return;
        }
    }

    for (int i = 1; i < n; i++)
    {
        arr[s[i] - 'a'][s[i - 1] - 'a']++;
    }
    int ans = 0;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (arr[i][j] >= 2 && i != j)
                ans = 1;

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
