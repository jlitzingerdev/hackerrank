#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <utility>

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

    if (min == 0) {
        cout << "ERROR 0 minimum" << endl;
        return;
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

void findMissingNumbers2(vector<int> A, map<int,int>& B, vector<int>& out)
{
    int tmp;
    int val;
    for (vector<int>::const_iterator it = A.begin(); it != A.end(); ++it) {
        tmp = *it;
        if (B[tmp] > 0) {
            val = B[tmp];
            B[tmp] = --val;
        }
    }

    for (map<int,int>::const_iterator it = B.begin(); it != B.end(); ++it) {
        if ((*it).second != 0) {
            out.push_back((*it).first);
        }
    }
}

int main()
{
    vector<int> A;
    //vector<int> B;
    map<int,int> Bm;
    vector<int> out;

    /*
    for (int i = 0; i < 10000; ++i) {
        for (int j = 100; j < 201; ++j) {
            B.push_back(j);
        }
    }
    */
    for (int i = 0; i < 10000; ++i) {
        for (int j = 102; j < 201; ++j) {
            A.push_back(j);
        }
    }

    int tmp;
    for (int i = 0; i < 10000; ++i) {
        for (int j = 100; j < 201; ++j) {
            if (Bm.find(j) != Bm.end()) {
                tmp = Bm[j];
                Bm[j] = ++tmp;
            } else {
                Bm[j] = 0;
            }
        }
    }

    //    findMissingNumbers(A, B, out);
    findMissingNumbers2(A, Bm, out);
    for_each(out.begin(), out.end(), print);
    cout << endl;
    return 0;
}
