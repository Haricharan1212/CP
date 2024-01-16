#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,c,i;
    cin >> t;
    while (t--)
    {cin >> n;string s;cin >> s;
        if (n&1)
        {
            cout << "YES" << endl;
            continue;
        }
        c = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] != s[n - 1 - i])
                c++;
        }
        if (c & 2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}