#include <vector>
using namespace std;
class Solution {
public:
    int numSquares_279(int n) {
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++) dp[i] = i;
        for (int i = 2, j = i * i; j <= n; i++, j = i * i) {
            for (int k = j; k <= n; k++) {
                dp[k] = min(dp[k], dp[k - j] + 1);
            }
        }
        return dp.back();

        // (2)Lagrange's four-square theorem
        // https://leetcode-cn.com/problems/perfect-squares/solution/wan-quan-ping-fang-shu-by-leetcode-solut-t99c/
    
        // (3)BFS
        // 广度优先搜索最短路径
    }
};