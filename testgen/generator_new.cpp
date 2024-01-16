#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

#define cout outputFile[tc]

// this folder needs testlib.h

// only three major functions needed:
// 1. rnd.next(a, b) -> returns a random number between a and b (inclusive)
// 2. shuffle(a.begin(), a.end()) -> shuffles the vector a
// 3. rnd.next("[a-z]{10}") -> returns a random string of length 10 -> "[a-z]{10}" is a regex

ofstream outputFile[500];

int32_t main()
{
    for (int tc = 1; tc <= 10; tc++)
    {
        outputFile[tc].open("input/input" + to_string(tc) + ".txt");

        // Problem: a + b, but for t tests

        // int t = rnd.next(1, 200000);

        // cout << t << endl;

        // while (t--){
        //     int a = rnd.next(-1000000000, 1000000000);
        //     int b = rnd.next(-1000000000, 1000000000);

        //     cout << a << " " << b << endl;
        // }

        // generate a random string in alphabetical order
        // only one test case

        // 5
        // abbde
        // badee -> NOT Valid

        // int n = rnd.next(1, 100);
        // cout << n << endl;

        // // string s = rnd.next("[a-z]{" + to_string(n) + "}");

        // vector<char> v(n);

        // for (int i = 0; i < n; i++)
        // {
        //     v[i] = rnd.next(0, 25) + 'a';
        // }
        // sort(v.begin(), v.end());

        // for (int i = 0; i < n; i++)
        // {
        //     cout << v[i];
        // }
        // cout << endl;

        // Add your code here

        // code to generate a random trees

        // int n = rnd.next(2, 10);
        // vector<int> a(n);

        // for (int i = 0; i < n; i++)
        // {
        //     a[i] = i + 1;
        // }
        // // 1, 2, 3, 4, 5, 6        

        // shuffle(a.begin(), a.end());

        // // 5, 6, 2, 3, 4, 1

        // vector<pair<int, int>> edges(n - 1);

        // for (int i = 1; i < n; i++)
        // {
        //     int num = rnd.next(0, i - 1);
            
        //     edges[i - 1] = {a[i], a[num]};
        // }

        // cout << n << endl;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     cout << edges[i].first << " " << edges[i].second << endl;
        // }

        // generate random string of size n
        int n = rnd.next(1, 100);
        cout << n << endl;

        
        string s = rnd.next("[a-z]{" + to_string(n) + "}");

        cout << s << endl;

        outputFile[tc].close();
    }

    return 0;
}