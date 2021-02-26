//
// Created by Pochita on 2021/2/25.
//
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose_867(vector<vector<int>>& matrix) {
        int column = matrix[0].size();
        int row = matrix.size();
        vector<vector<int>> result(column, vector<int>(row));
        for (int i = 0; i < column; ++i) {
            for (int j = 0; j < row; ++j) {
                result[i][j] = matrix[j][i];
            }
        }
        return result;
    }
};