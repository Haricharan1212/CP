#include <bits/stdc++.h>
using namespace std;
#define int long long

// 1, 6, 9
int evenas(int x)
{
    if (x > 6 && x < 9)
        return 9 - x;
    if (x > 1 && x < 6)
        return 6 - x;
    if (x == 0) return 1;
    return 0;
}

// 9 1 4 9
int makeperfectSquare(long double x)
{
    if (x > 4 && x < 9)
        return 9 - x;
    if (x > 1 && x < 4)
        return 4 - x;
    return 0;
}

int32_t main()
{
    int n;
    cin >> n;
    int ans = 0, k = 0;
 
    while (n != 0)
    {
        if (k % 2 == 1)
            ans += ((int) powl(10, k)) * evenas(n % 10);
        else
            ans += ((int) powl(10, k)) * makeperfectSquare(n % 10);

        k++;
        n /= 10;
    }

    cout << ans << endl;

}