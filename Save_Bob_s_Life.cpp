#include <bits/stdc++.h>
using namespace std;
int main(){int t;cin >> t;while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int s = 0, h = 0;
        for(int i = 0;i<n;i++) cin >> a[i], s += a[i];
        for(int i = 0;i<n;i++)
            h += min(a[i], s/2);
        if (s%2||(h != s)) cout << "YES" << "\n";else cout << "NO" << "\n";}return 0;
}