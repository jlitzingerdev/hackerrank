#include <iostream>
#include <vector>
#include <utility>

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
     */
    for (const auto& row : table) {
        for (const auto& c: row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return table[A.size()][B.size()];
}

void reconstruct_lcs(const std::vector<std::vector<int>>& table,
        const std::vector<int>& A,
        std::vector<int>::size_type i,
        std::vector<int>::size_type j,
        std::vector<int>& lcs)
{
    if ((i == 0) || (j == 0)) {
        return;
    }

    if (table[i-1][j] >= table[i][j]) { 
        reconstruct_lcs(table, A, i-1, j, lcs);
    } else if (table[i][j-1] > table[i][j]) {
        reconstruct_lcs(table, A, i, j-1, lcs);
    } else {
        reconstruct_lcs(table, A, i-1, j-1, lcs);
        lcs.push_back(A[i-1]);
    }
}

int main(int argc, char *argv[])
{
    std::vector<int> A{3,4,1,2,1,3};
    std::vector<int> B{1,2,3,4,1};
    std::vector<int> lcs;

    std::vector<std::vector<int>> table{A.size() + 1}; //This is to match algorithm conceptually, FIXME
    std::cout << "LCS len: " << lcs_length(A, B, table) << std::endl;
    reconstruct_lcs(table, A, A.size(), B.size(), lcs);
    std::cout << "LCS: ";
    for (auto val: lcs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
