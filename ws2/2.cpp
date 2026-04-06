#include <iostream>
#include <vector>


int count_le(const std::vector< std::vector<int> > &matrix, int target, int n) {
    int count = 0;
    int row = n - 1;
    int col = 0;
    while (row >= 0 && col < n) {
        if (matrix[row][col] <= target) {
            count += row + 1;
            col++;
        } else {
            row--;
        }
    }
    return count;
}


int kthSmallest(std::vector< std::vector<int> > &matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    int res = low;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (count_le(matrix, mid, n) >= k) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}


int main() {
    std::vector< std::vector<int> > matrix;
    int k = 8;
    std::vector<int> row1 = {1,  5,  9};
    std::vector<int> row2 = {10,  11,  13};
    std::vector<int> row3 = {12,  13,  15};
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    std::cout << "Answer: " << kthSmallest(matrix, k) << '\n';
    return 0;
}
