#include <iostream>
#include <vector>

using namespace std;

bool canGenerateSubsets(vector<int> &arr, int targetSum, int currentIndex, vector<int> &currentSubset, int currentSum, int numSubsets)
{
    if (currentSum == targetSum && currentSubset.size() > 0)
    {
        if (numSubsets == 4)
        {
            return true;
        }
        return canGenerateSubsets(arr, targetSum, 0, currentSubset, 0, numSubsets + 1);
    }

    if (currentIndex == (long long)arr.size() || currentSum > targetSum)
    {
        return false;
    }

    // Include the current element in the subset
    currentSubset.push_back(arr[currentIndex]);
    bool withCurrent = canGenerateSubsets(arr, targetSum, currentIndex + 1, currentSubset, currentSum + arr[currentIndex], numSubsets);
    currentSubset.pop_back();

    // Exclude the current element from the subset
    bool withoutCurrent = canGenerateSubsets(arr, targetSum, currentIndex + 1, currentSubset, currentSum, numSubsets);

    return withCurrent || withoutCurrent;
}

bool hasFourDistinctSubsets(vector<int> &arr, int targetSum)
{
    vector<int> currentSubset;
    return canGenerateSubsets(arr, targetSum, 0, currentSubset, 0, 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int targetSum = 10;

    if (hasFourDistinctSubsets(arr, targetSum))
    {
        cout << "There are four distinct non-intersecting subsets that sum to " << targetSum << "." << endl;
    }
    else
    {
        cout << "There are no four distinct non-intersecting subsets that sum to " << targetSum << "." << endl;
    }

    return 0;
}
