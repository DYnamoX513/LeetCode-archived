//
// Created by Pochita on 2021/3/1.
//
#include <vector>
using namespace std;

//No.303
class NumArray {
public:
    int *sums;

    explicit NumArray(vector<int> &nums) {
        int length = nums.size();
        sums = new int[length + 1];
        int sum = sums[0] = 0;
        for (int i = 0; i < length; ++i) {
            sums[i + 1] = sum += nums[i];
        }
    }

    int sumRange(int i, int j) const {
        return sums[j + 1] - sums[i];
    }

    ~NumArray() {
        delete sums;
    }
};

//No.304
class NumMatrix {
public:
    int **sums = nullptr;
    int sRow;
    int sCol;

    explicit NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;

        sRow = row +1;
        sCol = col +1;
        sums = new int *[sRow];
        sums[0] = new int[sCol]();
        for (int i = 0, j = 1; i < row; ++i, ++j) {
            sums[j] = new int[sCol];
            sums[j][0] = 0;
            int m = 0;
            for (int k = 0; k < col; ++k) {
                m =
                sums[j][k + 1] = sums[j][k] + sums[j - 1][k + 1] - sums[j - 1][k] + matrix[i][k];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) const {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
    
    ~NumMatrix() {
        if (sums == nullptr) return;
        for (int i = 0; i < sRow; ++i) {
            delete []sums[i];
        }
        delete []sums;
    }
};

class Solution {
public:

};

int main() {
    Solution s;
    vector<vector<int>> test({
                                     {},
    });
    NumMatrix * n = new NumMatrix(test);
    n->sumRegion(0,2,1,5);
}