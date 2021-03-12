//
// Created by Pochita on 2021/3/3.
//
#include <queue>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSerialization_331(string preorder) {
        int degree = 1;
        int length = preorder.length(), curr = 0;
        while (curr < length) {
            if (degree == 0)
                return false;
            if (preorder[curr] == '#') {
                curr += 2;
                degree -= 1;
            } else {
                while (curr < length && preorder[curr] != ',')
                    curr++;
                curr++;
                degree += 1;
            }
        }
        return degree == 0;
    }

    vector<int> countBits_338(int num) {
        //0     0
        //0,1   1
        //0,1,1,2   3
        //0,1,1,2,1,2,2,3   7
        long pow2 = 2;
        int count = 1;
        vector<int> result(num + 1, 0);
        while (count <= num) {
            int upper = min(static_cast<long>(num), pow2 - 1) - pow2 / 2;
            for (int i = 0; i <= upper; ++i, ++count) {
                result[count] = (result[i] + 1);
            }
            pow2 *= 2;
        }
        return result;
    }
};

int main() {
    Solution s;
    s.isValidSerialization_331("9,3,4,#,#,1,#,#,2,#,6,#,#");
}