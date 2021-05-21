//
// Created by Pochita on 2021/5/19.
//
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numRabbits_781(vector<int> &answers) {
        unordered_map<int, int> counts;
        for (const int answer:answers) {
            counts[answer]++;
        }
        int answer = 0;
        for (const auto &[f, s]:counts) {
            int group = f + 1;
            answer += ((s - 1) / group + 1) * group;
        }
        return answer;
    }
};