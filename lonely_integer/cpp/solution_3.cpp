#include <vector>
#include <iostream>
#include <limits>

using namespace std;


int findLonelyInt(const vector<int> &A)
{
    int v = 0; 
    for (vector<int>::const_iterator it = A.begin(); it != A.end(); ++it) {
        v ^= *it;
    }

    return v;
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
