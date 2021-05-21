#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;
class Solution{
public:
    int findCircleNums_547(vector<vector<int> > &isConnected) {
        int n = isConnected.size();
        int count = 0;
        stack<int> connect;
        for (int i = 0; i < n; ++i) {
            if (isConnected[i][i] == 0)
                continue;
            connect.push(i);
            count++;
            while (!connect.empty()) {
                int curr = connect.top();
                connect.pop();
                for (int j = 0; j < n; ++j) {
                    if (isConnected[curr][j] && isConnected[j][j] && i != j) {
                        isConnected[j][j] = 0;
                        connect.push(j);
                    }
                }
            }
        }

        return count;
    }

    int leastBricks_554(vector<vector<int>>& wall) {
        unordered_map<int, int> rift;
        for (const auto &row:wall) {
            int sum = 0;
            int interval = row.size() - 1;
            for (int i = 0; i < interval; ++i) {
                sum += row[i];
                rift[sum]++;
            }
        }
        int result = 0;
        for (auto &i : rift)
            result = max(result, i.second);

        return wall.size() - result;
    }
};

int main() {

}