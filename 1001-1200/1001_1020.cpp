//
// Created by Pochita on 2021/4/1.
//

class Solution {
public:
    int clumsy_1006(int N) {
        int result = 0, partial = N--, op = 0, sign = 1;
        while (N > 0) {
            switch (op) {
                case 0:
                    partial *= N--;
                    break;
                case 1:
                    partial /= N--;
                    break;
                case 2:
                    result += sign * partial;
                    partial = N--;
                    sign = 1;
                    break;
                case 3:
                    result += sign * partial;
                    partial = N--;
                    sign = -1;
                    break;
            }
            op = (op + 1) % 4;
        }
        return result + sign * partial;
    }

    //No.1006的数学解法
    int clumsy_mathematical(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
};