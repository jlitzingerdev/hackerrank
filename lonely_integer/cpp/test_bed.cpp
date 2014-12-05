#include <vector>
#include <set>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int findLonelyInt1(vector<int> &A)
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

int findLonelyInt2(const vector<int> &A)
{
    set<int> s;
   
    int v = 0; 
    for (vector<int>::const_iterator it = A.begin(); it != A.end(); ++it) {
        v = *it;
        if (s.count(v) == 0) {
            s.insert(v);
        } else {
            s.erase(v);
        }
    }

    if (s.size() != 1) {
        cout << "ERR: Size == " << s.size() << endl;
    }

    return *s.begin();
}

int findLonelyInt3(const vector<int> &A)
{
    int v = 0;
    for (vector<int>::const_iterator it = A.begin(); it != A.end(); ++it) {
        v ^= *it;
    }

    return v;
}

int main(void)
{

    vector<int> A;
    for (int i = 490000; i > 0; --i) {
        A.push_back(i);
        A.push_back(i);
    }
    A.push_back(5000000);

    //int li = findLonelyInt1(A);
    int li = findLonelyInt2(A);
    //int li = findLonelyInt3(A);
    cout << "result:" << li << endl;

    return 0;
}
