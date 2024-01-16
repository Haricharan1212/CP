#include <bits/stdc++.h>
using namespace std;
int main() {
    int T,a,b,d,i,f;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        d = b - a;
        if (!d) {
            cout << "YES\n";
            continue;
        }
        i = f = 1;
        while (i * i <= d) {
            if (d % i == 0) {
                if (i >= a || d / i >= a) {
                    cout << "YES\n";
                    f = 0;
                }
            }
            i++;
            if (!f) break;
        }
        if (f) cout << "NO\n";
    }

    cout << (1LL << 50) + (1LL << 30) << endl;
}
