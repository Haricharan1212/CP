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

// SECRODEFEDORCES
// CODEFORCESECROFEDOC

#include<bits/stdc++.h>
using namespace std;

string makePalindrome(string s) {
    int n = s.size();
    int i = 0, j = n - 1;
    string res = "";
    while (i <= j) {
        if (s[i] == s[j]) {
            res += s[i];
            if (i != j) res = s[i] + res;
            i++;
            j--;
        } else if (s[i] < s[j]) {
            res = s[i] + res + s[i];
            j--;
        } else {
            res = s[j] + res + s[j];
            i++;
        }
    }
    return res;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    cout << makePalindrome(s) << endl;

    // int left = 0, right = n - 1;
    // string front, back;

    // while (left <= right)
    // {
    //     if (left == right)
    //     {
    //         front += s[left];
    //         break;
    //     }
    //     else if (s[left] == s[right]){
    //         front += s[left];
    //         back += s[right];
    //         left++;
    //         right--;
    //     }
    //     else {
    //         if (dp[left][right - 1] < dp[left + 1][right]){
    //             back += s[right];
    //             front += s[right];
    //             right--;
    //         }
    //         else{
    //             back += s[left];
    //             front += s[left];
    //             left++;
    //         }

    //     }
    // }

    // string frontans;
    // string backans;

    // while (left <= right)
    // {
    //     if (left == right){
    //         frontans += s[left];
    //         break;
    //     }

    //     else if (s[left] == s[right])
    //     {
    //         frontans += s[left];
    //         backans += s[right];

    //         left++;
    //         right--;
    //     }
    //     else
    //     {
    //         if (s[left] < s[right]){
    //             frontans += s[left];
    //             backans += s[left];
    //             left++;
    //         }
    //         else{
    //             frontans += s[right];
    //             backans += s[right];
    //             right--;
    //         }
    //         ops++;
    //     }
    // }

    // reverse(back.begin(), back.end());

    // cout << front + back << "\n";
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