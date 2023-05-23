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

// This function takes the upper bound as an argument! This is very useful to generate
// tests with certain parameters.
void write(int tc, int upperBound)
{

    int a = glr(1, upperBound);
    int b = glr(1, upperBound);

    cout << a << " " << b << endl;

    return;
}

int32_t main()
{
    // This code generates 10 tests total! 3 test cases have input from 1 to 5, 4 test cases
    // have input from 1 to 10000, and 3 test cases have input from 1 to 10^9.

    int tc = 0, N = 0;

    N = 3;
    for (int i = 0; i < N; i++)
    {
        outputFile[tc].open("input/input" + to_string(tc + 1) + ".txt");

        write(tc, 5);
        outputFile[tc].close();
        tc++;
    }

    N = 4;
    for (int i = 0; i < N; i++)
    {
        outputFile[tc].open("input/input" + to_string(tc + 1) + ".txt");

        write(tc, 10000);
        outputFile[tc].close();
        tc++;
    }

    N = 3;
    for (int i = 0; i < N; i++)
    {
        outputFile[tc].open("input/input" + to_string(tc + 1) + ".txt");

        write(tc, 1000000000);
        outputFile[tc].close();
        tc++;
    }

    return 0;
}