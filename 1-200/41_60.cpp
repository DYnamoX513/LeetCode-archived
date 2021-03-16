//
// Created by Pochita on 2021/3/15.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder_54(vector<vector<int>> &matrix) {
        int direction = 0; //0 go right; 1 down; 2 left; 3 up
        int rightMax = matrix[0].size(), downMax = matrix.size(), upMax = -1, leftMax = -1, total = rightMax * downMax;
        vector<int> result(total);
        int i = 0;
        while (i < total)
            switch (direction) {
                case 0:
                    upMax++;
                    for (int j = leftMax + 1; j < rightMax; ++j, ++i)
                        result[i] = matrix[upMax][j];
                    direction = 1;
                    break;
                case 1:
                    rightMax--;
                    for (int j = upMax + 1; j < downMax; ++j, ++i)
                        result[i] = matrix[j][rightMax];
                    direction = 2;
                    break;
                case 2:
                    downMax--;
                    for (int j = rightMax - 1; j > leftMax; --j, ++i)
                        result[i] = matrix[downMax][j];
                    direction = 3;
                    break;
                case 3:
                    leftMax++;
                    for (int j = downMax - 1; j > upMax; --j, ++i)
                        result[i] = matrix[j][leftMax];
                    direction = 0;
                    break;
            }
        return result;
    }

    vector<vector<int>> generateMatrix_59(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int direction = 0; //0 go right; 1 down; 2 left; 3 up
        int rightMax = n, downMax = n, upMax = -1, leftMax = -1, total = n * n;
        int i = 0;
        while (i < total)
            switch (direction) {
                case 0:
                    upMax++;
                    for (int j = leftMax + 1; j < rightMax; ++j)
                        result[upMax][j] = ++i;
                    direction = 1;
                    break;
                case 1:
                    rightMax--;
                    for (int j = upMax + 1; j < downMax; ++j)
                        result[j][rightMax] = ++i;
                    direction = 2;
                    break;
                case 2:
                    downMax--;
                    for (int j = rightMax - 1; j > leftMax; --j)
                        result[downMax][j] = ++i;
                    direction = 3;
                    break;
                case 3:
                    leftMax++;
                    for (int j = downMax - 1; j > upMax; --j)
                        result[j][leftMax] = ++i;
                    direction = 0;
                    break;
            }
        return result;
    }
};
