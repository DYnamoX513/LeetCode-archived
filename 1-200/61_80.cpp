//
// Created by Pochita on 2021/3/21.
//
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes_73(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        bool firstRow = false, firstColumn = false;
        for (int i = 0; i < row; ++i)
            if (matrix[i][0] == 0) {
                firstColumn = true;
                break;
            }
        for (int i = 0; i < column; ++i)
            if (matrix[0][i] == 0) {
                firstRow = true;
                break;
            }

        for (int i = 1; i < row; ++i)
            for (int j = 1; j < column; ++j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for (int i = 1; i < row; ++i)
            if (matrix[i][0] == 0)
                for (int j = 1; j < column; ++j)
                    matrix[i][j] = 0;
        for (int i = 1; i < column; ++i)
            if (matrix[0][i] == 0)
                for (int j = 1; j < row; ++j)
                    matrix[j][i] = 0;

        if (firstRow)
            for (int i = 0; i < column; ++i)
                matrix[0][i] = 0;
        if (firstColumn)
            for (int i = 0; i < row; ++i)
                matrix[i][0] = 0;
    }
};