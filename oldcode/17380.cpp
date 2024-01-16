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

void solve()
{
    ll n;
    cin >> n;

    vi a(n);
    deque<ll> fire, frost, firee, frostt;
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (a[i] == 0)
            fire.push_back(x);
        else
            frost.push_back(x);
    }

    sort(fire.begin(), fire.end());
    sort(frost.begin(), frost.end());

    firee = fire;
    frostt = frost;

    ll ans = 0;
    if (fire.size() == 0)
    {
        for (auto i : frost)
            ans += i;
        cout << ans << endl;
        return;
    }
    if (frost.size() == 0)
    {
        for (auto i : fire)
            ans += i;
        cout << ans << endl;
        return;
    }
    ans = 0;
    {
        ll ind = 0;
        ans += fire[0];
        fire.pop_front();
        while (fire.size() != 0 || frost.size() != 0)
        {
            ind++;
            if (fire.size() == 0)
            {
                ans += 2 * frost[frost.size() - 1], frost.pop_back();
                for (auto i : frost)
                    ans += i;
                break;
            }
            else if (frost.size() == 0)
            {
                ans += 2 * fire[fire.size() - 1], fire.pop_back();
                for (auto i : fire)
                    ans += i;
                break;
            }
            if (ind % 2 == 0)
                ans += 2 * fire[fire.size() - 1], fire.pop_back();
            else
                ans += 2 * frost[frost.size() - 1], frost.pop_back();
        }
    }
    fire = firee;
    frost = frostt;
    ll best = ans;
    ans = 0;
    {
        ll ind = 1;
        ans += frost[0];
        frost.pop_front();
        while (fire.size() != 0 || frost.size() != 0)
        {
            ind++;
            if (fire.size() == 0)
            {
                ans += 2 * frost[frost.size() - 1], frost.pop_back();
                for (auto i : frost)
                    ans += i;
                break;
            }
            else if (frost.size() == 0)
            {
                ans += 2 * fire[fire.size() - 1], fire.pop_back();
                for (auto i : fire)
                    ans += i;
                break;
            }
            if (ind % 2 == 0)
                ans += 2 * fire[fire.size() - 1], fire.pop_back();
            else
                ans += 2 * frost[frost.size() - 1], frost.pop_back();
        }
    }
    // cout << ans << ' ' << best << endl;
    best = max(ans, best);
    cout << best << endl;
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
