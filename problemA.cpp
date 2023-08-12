#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define ll long long

bool findSubsetIndices(vector<int> &arr, int targetSum, int currentIndex, int currentSum, int repetitions, vector<bool> &done)
{

    if (currentSum == targetSum && repetitions == 3)
    {
        return true;
    }

    if (currentIndex == (ll)arr.size() || currentSum > targetSum)
    {
        return false;
    }

    while (done[currentIndex])
    {
        currentIndex++;
        if (currentIndex == (ll)arr.size())
        {
            return false;
        }
    }

    if (currentSum == targetSum)
    {
        for (auto i : done)
            cout << i << ' ';
        cout << endl;
        repetitions++;
        currentSum = 0;
        currentIndex = 0;
    }

    done[currentIndex] = true;
    // bool withCurrent = findSubsetIndices(arr, targetSum, currentSubset, currentIndex + 1, currentSum + arr[currentIndex], repetitions + 1, resultIndices);
    bool withCurrent = findSubsetIndices(arr, targetSum, currentIndex + 1, currentSum + arr[currentIndex], repetitions, done);

    done[currentIndex] = false;

    bool withoutCurrent = findSubsetIndices(arr, targetSum, currentIndex + 1, currentSum, repetitions, done);

    return withCurrent || withoutCurrent;
}

int solution(vector<int> &A)
{
    set<int, greater<int>> sums;

    for (int i = 0; i < (long long)A.size(); i++)
    {
        sums.insert(A[i]);
        for (int j = i + 1; j < (long long)A.size(); j++)
        {
            sums.insert(A[i] + A[j]);
        }
    }

    for (auto i : sums)
    {
        cout << i << ' ';

        vector<int> b = A;
        vector<bool> done(b.size(), false);

        findSubsetIndices(b, i, 0, 0, 0, done);

        cout << endl;

        // if (findSubsetIndices(b, i, 0, 0, 0, done))
        // {
        //     return i;
        // }
    }

    return 0;
}

int32_t main()
{

    vector<int> A = {1, 1, 1, 1};
    cout << solution(A) << endl;

    return 0;
}