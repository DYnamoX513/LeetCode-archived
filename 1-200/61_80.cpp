//
// Created by Pochita on 2021/3/21.
//
#include <vector>
#include <ListNode.h>

using namespace std;

class Solution {
public:
    ListNode *rotateRight_61(ListNode *head, int k) {
        if (head == nullptr || k == 0) return head;
        int length = 1;
        auto rear = head;
        while (rear->next != nullptr) {
            rear = rear->next;
            length++;
        }
        int position = length - k % length;
        if (position == length) return head;
        rear->next = head;
        for (int i = 0; i < position; ++i)
            rear = rear->next;
        auto ret = rear->next;
        rear->next = nullptr;
        return ret;
    }

    void setZeroes_73(vector<vector<int>> &matrix) {
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

    bool searchMatrix_74(vector<vector<int>> &matrix, int target) {
        int row = matrix.size(), col = matrix[0].size(), left = 0, right = row - 1, pos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid][0];
            if (val < target) {
                left = mid + 1;
                pos = mid;
            } else if (val > target)
                right = mid - 1;
            else
                return true;
        }
        if (pos < 0) return false;
        left = 0;
        right = col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[pos][mid];
            if (val < target)
                left = mid + 1;
            else if (val > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec({{1, 3, 5}});
    s.searchMatrix_74(vec, 4);
}