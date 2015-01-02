#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

void print(int& val)
{
    cout << val << " ";
}

void findMissingNumbers(vector<int> A, vector<int>& B, vector<int>& out)
{
    if (A.size() == B.size()) {
        return;
    }

    int max = 0;
    int min = 99999;

    int tmp;
    for (vector<int>::const_iterator it = B.begin(); it != B.end(); ++it) {
        tmp = *it;
        if (tmp > max) {
            max = tmp;
        }
        if (tmp < min) {
            min = tmp;
        }
    }

    int size = (max - min) + 1;
    vector<int> t(size, 0);

    for (vector<int>::const_iterator it = B.begin(); it != B.end(); ++it) {
        tmp = *it;
        t[tmp % min]++;
    }

    for (vector<int>::const_iterator it = A.begin(); it != A.end(); ++it) {
        tmp = *it;
        t[tmp % min]--;
    }

    for (int i = 0; i < size; ++i) {
        if (t[i] > 0) {
            out.push_back(i + min);
        }
    }
    
}

void readInput(vector<int>& in)
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        in.push_back(tmp);
    }
}

int main()
{

    vector<int> A;
    vector<int> B;
    readInput(A);
    readInput(B);

    vector<int> out;
    findMissingNumbers(A, B, out);
    for_each(out.begin(), out.end(), print);
    cout << endl;
    return 0;
}
