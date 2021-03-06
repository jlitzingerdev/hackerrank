#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include<algorithm>

int  lcs_length(const std::vector<int>& A, const std::vector<int>& B,
        std::vector<std::vector<int>> &table)
{
    std::vector<int>::size_type a_bound = A.size() + 1;
    std::vector<int>::size_type b_bound = B.size() + 1;

    for (auto& row : table) {
        row.resize(b_bound, 0);
    }

    /**
     * Be careful here, the table has an extra row and column, but
     * the indexing on the sequences is zero based, so i-1 means one
     * thing when referencing the sequence and another when referencing
     * the table
     * FIXME
     */
    for (auto i = 1; i < a_bound; ++i) {
        for (auto j = 1; j < b_bound; ++j) {
            if (A[i-1] == B[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            } else {
                if (A[i-1] >= B[j-1]) {
                    table[i][j] = table[i-1][j];
                } else {
                    table[i][j] = table[i][j-1];
                }
            }
        }
    }

    /**
     * c[i][j] is the length of the LCS of subproblems to that point
    for (const auto& row : table) {
        for (const auto& c: row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    */

    return table[A.size()][B.size()];
}

void reconstruct_lcs(const std::vector<std::vector<int>>& table,
        const std::vector<int>& A,
        std::vector<int>::size_type j,
        std::vector<int>& lcs)
{
    std::vector<int>::size_type i = A.size();
    while ((i != 0) && (j != 0)) {
        if (table[i-1][j] >= table[i][j]) {
            --i;
        } else if (table[i][j-1] > table[i][j]) {
            --j;
        } else {
            lcs.push_back(A[i-1]);
            --i;
            --j;
        }
    }
    std::reverse(std::begin(lcs), std::end(lcs));
}

int main(int argc, char *argv[])
{
    std::vector<int> A{3,4,1,2,1,3};
    std::vector<int> B{1,2,3,4,1};
    std::vector<int> lcs;

    std::vector<std::vector<int>> table{A.size() + 1}; //This is to match algorithm conceptually, FIXME
    lcs_length(A, B, table);
    reconstruct_lcs(table, A, B.size(), lcs);
    for (auto val: lcs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
