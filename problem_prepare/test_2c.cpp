#include <bits/stdc++.h>

using namespace std;

// Initializing Random Number Generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Returns a random number between [1, r]
int gr(int r)
{
    uniform_int_distribution<int> uid(0, r - 1);
    int val = uid(rng);
    return val + 1;
}

// Returns a random number between [l, r]
int glr(int l, int r)
{
    int dif = r - l + 1;
    int x = gr(dif) + l - 1;
    return x;
}

#define cout outputFile[tc]
#define MAX_TC 200

vector<ofstream> outputFile(MAX_TC);

// Create an "input" folder in the same directory as this file.
// Contribute to whatever you want to output in each test ONLY here. Nowhere else.
// If necessary, you can pass in more inputs to the write function, like the upper bound
// for instance. Look at the sample code!
void write(int tc)
{
    return;
}

int32_t main()
{
    int tc = 0, N = 0;

    // This N is the number of times you want to run the code! Copy paste this codeblock to
    // generate different kinds of cases.
    N = 7;
    for (int i = 0; i < N; i++)
    {
        outputFile[tc].open("input/input" + to_string(tc + 1) + ".txt");

        write(tc);
        outputFile[tc].close();
        tc++;
    }

    return 0;
}