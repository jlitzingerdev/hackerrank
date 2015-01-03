#include <vector>
#include <iostream>
#include <limits>

using namespace std;

void findMissingNumbers(vector<int> A, vector<int>& B, vector<int>& out)
{
    if (A.size() == B.size()) {
        return;
    }

    int max = 0;
    int min = 99999;

    for (const auto i : B) {
        if (i > max) {
            max = i;
        }
        if (i < min) {
            min = i;
        }
    }

    int size = (max - min) + 1;
    vector<int> t(size, 0);

    for (const auto i : B) {
        t[i % min]++;
    }

    for (const auto i : A) {
        t[i % min]--;
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
    for (const auto val : out) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
