#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        y

            int minOnes = n;

        for (int i = 0; i < n; i++)
        {
            int firstHalfOnes = ceil((double)i / k);
            int secondHalfOnes = ceil((double)(n - i + 1) / k);
            int totalOnes = firstHalfOnes + secondHalfOnes;

            minOnes = min(minOnes, totalOnes);
        }

        cout << minOnes << endl;
    }

    return 0;
}