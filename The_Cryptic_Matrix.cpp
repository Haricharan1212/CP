#include <bits/stdc++.h>
using namespace std;
#define a auto
#define z int
#define v vector
int32_t main()
{
    z s,l,t,n,m,j;
    cin >> t;
    while (t--)
    {
        cin>>n>>m;
        v<v<z>> r(n,v<z>(m));
        l = 1;
        for (s = 0; s <= n + m; s++)
        {
            for (j = 0; j <= s; j++)
            {
                if (s - j >= n || j >= m)
                    continue;
                r[s - j][j] = l++;
            }
        }
        for (a i : r)
        {
            for (a j : i)
                cout << j << ' ';
            cout << endl;
        }
    }
}