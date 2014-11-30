#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * This not an optimal solution, just the first I came up with.
 */

int findLonelyInt(vector<int> &A)
{
    if (A.size() == 1) {
        return A[0];
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i += 2) {
        if (((i + 1) >= A.size()) || (A[i] != A[i+1])) {
            return A[i];
        }
    }
    return -1;
}

int main(void)
{
    int N = 1;
    cin >> N;

    if (((N % 2) != 1)  || (N >= 100)) {
        cerr << "Bad input specification, N must be odd and < 100." << endl;
        return -1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> A;
    int tmp = 0;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        A.push_back(tmp);
    }
    int li = findLonelyInt(A);
    cout << li << endl;

    return 0;
}
