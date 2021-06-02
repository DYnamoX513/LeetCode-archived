#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> canEat_1744(vector<int>& candiesCount,
                             vector<vector<int>>& queries) {
        vector<bool> result;
        int length = candiesCount.size();
        vector<long long> sumBefore(length + 1);
        sumBefore[0] = 0;
        for (int i = 0; i < length; i++)
            sumBefore[i + 1] = sumBefore[i] + candiesCount[i];

        for (const auto& query : queries) {
            long long leastEat = query[1],
                      mostEat = (long long)(query[1] + 1) * query[2],
                      candyBefore = sumBefore[query[0]];
            result.emplace_back(candyBefore < mostEat &&
                                candyBefore + candiesCount[query[0]] >
                                    leastEat);
        }
        return result;
    }
};
