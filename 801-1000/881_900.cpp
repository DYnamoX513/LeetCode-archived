//
// Created by Pochita on 2021/2/28.
//
#include "vector"
using namespace std;
class Solution {
public:
    bool isMonotonic_896(vector<int>& A) {
        int length = A.size();
        if (length < 3) return true;
        int i = 1;
        while (i < length && A[i - 1] == A[i]) {
            i++;
        }

        if (i == length) return true;
        if (A[i - 1] < A[i]) {
            while (i < length) {
                if (A[i - 1] > A[i]) return false;
                i++;
            }
        } else {
            while (i < length) {
                if (A[i - 1] < A[i]) return false;
                i++;
            }
        }
        return true;
    }
};