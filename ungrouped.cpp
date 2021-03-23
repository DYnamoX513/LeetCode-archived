//
// Created by Pochita on 2021/3/23.
//
#include <map>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int getNumberOfBacklogOrders_1801(vector<vector<int>>& orders) {
        typedef pair<int, int> P2;
        priority_queue<P2, vector<P2>, greater<>> sellOrder;
        priority_queue<P2> buyOrder;
        for (auto &order: orders) {
            if (order[2] == 0) {
                int price = order[0];
                int &amount = order[1];
                while (!sellOrder.empty()) {
                    auto t = sellOrder.top();
                    if (t.first <= price) {
                        if (t.second > amount) {
                            auto p = make_pair(t.first, t.second - amount);
                            sellOrder.pop();
                            sellOrder.push(p);
                            amount = 0;
                            break;
                        } else {
                            amount -= t.second;
                            sellOrder.pop();
                        }
                    } else
                        break;
                }
                if (amount > 0)
                    buyOrder.push(make_pair(price, amount));
            } else {
                int price = order[0];
                int &amount = order[1];
                while (!buyOrder.empty()) {
                    auto t = buyOrder.top();
                    if (t.first >= price) {
                        if (t.second > amount) {
                            auto p = make_pair(t.first, t.second - amount);
                            buyOrder.pop();
                            buyOrder.push(p);
                            amount = 0;
                            break;
                        } else {
                            amount -= t.second;
                            buyOrder.pop();
                        }
                    } else
                        break;
                }
                if (amount > 0)
                    sellOrder.push(make_pair(price, amount));
            }
        }
        long result = 0;
        while (!sellOrder.empty()) {
            result += sellOrder.top().second;
            sellOrder.pop();
        }
        while (!buyOrder.empty()) {
            result += buyOrder.top().second;
            buyOrder.pop();
        }
        return result % 1000000007;
    }

    int maxValue_1802(int n, int index, int maxSum) {
        //二分法寻找
        if (n == 1) return maxSum;
        maxSum -= n;
        long min = 0, max = maxSum;
        while (min < max - 1) {
            long sum = 0;
            long current = min + (max - min) / 2;
            if (current - index > 1)    //截断的等差数列
                sum += (current + current - index) * (index + 1) / 2;
            else    //等差数列
                sum += (current + 1) * current / 2;

            if (current - n + index <= 0) //等差数列
                sum += (current + 1) * current / 2;
            else //截断的等差数列
                sum += (current + current - n + index + 1) * (n - index) / 2;
            sum -= current; //多加了一次

            if (sum > maxSum)
                max = current;
            else if (sum == maxSum)
                return current + 1;
            else
                min = current;
        }
        return min + 1;
    }

    int maxValue_1802_another(int n, int index, int maxSum) {
        if (n == 1) return maxSum;
        maxSum -= n;
        int left = index, right = index, remain = maxSum, count = 1, rightBound = n - 1; //[left,right]
        while (left > 0 || right < rightBound) {  //当左右两边还未触及边界
            int add = right - left + 1; //该轮需要增加的值
            if (add <= remain) {
                count++;
                remain -= add;
                left = max(0, left - 1);
                right = min(rightBound, right + 1);
            } else
                break;
        }
        count += remain / n;    //已经扩展到整个数组 or 不能继续增加（(int)remain / n = 0)
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> orders = {
            {{7, 1000000000, 1}, {15, 3, 0}, {5, 999999995, 0}, {5, 1, 1}}
    };
    s.getNumberOfBacklogOrders_1801(orders);
}