#include <vector>
#include <limits>
#include <iostream>

using namespace std;

int gcd(int m, int n)
{
    int tmp = 0;
    while (m != 0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}

int maximalSquaresCount(int l, int b)
{
    if ((l == 0) || (b == 0)) {
        return 0;
    }

    if (l == b) {
        return 1;
    }
    //find gcd
    int gdiv = gcd(l,b);
    int Asq = gdiv * gdiv;

    return (l * b) / Asq;
}

int main(int argc, char *argv[])
{

    vector<int> squares;
    int T;
    cin >> T;
    int l;
    int b;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < T; ++i) {
        cin >> l;
        cin >> b;
        squares.push_back(maximalSquaresCount(l,b));
    }

    for (auto v : squares) {
        cout << v << endl;
    }

    return 0;
}
