//
// Created by 段宇昕 on 2021/3/4.
//
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    //Bad Solution
    int maxEnvelopes_354(vector<vector<int>>& envelopes) {
        int length = envelopes.size();
        if (length == 1) return 1;
        auto increase = [](vector<int> &a, vector<int> &b) { return a[0] < b[0] || a[0] == b[0] && a[1] < b[1]; };
        sort(envelopes.begin(), envelopes.end(), increase);
        //最多能套*个    所有能套*个的信封，其中最小的height
        map<int, pair<vector<int>, int>> maxOfEnvelopes;
        maxOfEnvelopes[1] = make_pair(vector<int>({0}), envelopes[0][1]);

        for (int i = 1; i < length; ++i) {
            int width = envelopes[i][0], height = envelopes[i][1];
            //找到能套最多的下一级信封
            bool find = false;
            for (auto iter = maxOfEnvelopes.rbegin(); iter != maxOfEnvelopes.rend() && !find; ++iter) {
                if (height < iter->second.second) continue;
                for (int j:iter->second.first) {
                    if (width > envelopes[j][0] && height > envelopes[j][1]) {
                        find = true;
                        auto update = maxOfEnvelopes.find(iter->first + 1);
                        if (update == maxOfEnvelopes.end())
                            maxOfEnvelopes[iter->first + 1] = make_pair(vector<int>({i}), height);
                        else {
                            update->second.first.push_back(i);
                            update->second.second = min(update->second.second, height);
                        }
                        break;
                    }
                }
            }
            if (!find) {
                auto &p = maxOfEnvelopes[1];
                p.first.push_back(i);
                p.second = min(p.second, height);
            }
        }
        return maxOfEnvelopes.rbegin()->first;
    }

    //参考No.300最长递增子序列，二分查找法
    //Better One
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int length = envelopes.size();
        if (length == 1) return 1;
        auto increaseThenDecrease = [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
        };
        sort(envelopes.begin(), envelopes.end(), increaseThenDecrease);

        //表示 h 的前 i 个元素可以组成的长度为 j 的最长严格递增子序列的末尾元素的最小值
        vector<int> maxSub({envelopes[0][1]});
        int subLength = 1;
        for (int i = 1; i < length; ++i) {
            int height = envelopes[i][1];
            if (height > maxSub.back()) {
                maxSub.push_back(height);
                subLength++;
            } else {
                //二分查找
                int l = 0, u = subLength - 1;
                while (l <= u) {
                    int mid = (l + u) / 2;
                    if (height > maxSub[mid]) {
                        l = mid + 1;
                    } else {
                        u = mid - 1;
                    }
                }
                maxSub[l] = height;
                /*auto iter = lower_bound(maxSub.begin(),maxSub.end(),height);
                *iter = height;*/
            }
        }
        return subLength;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a({
                                  {2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}
    });
    s.maxEnvelopes_354(a);
}