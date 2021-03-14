#include <algorithm>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex_724(vector<int> &nums) {
        int length = nums.size();
        if (length < 2) {
            return 0;
        }
        //起始
        int leftSum = 0;
        int rightSum = 0;
        //添加辅助位
        nums.emplace_back(0);
        for (int i = 1; i < length; i++) {
            rightSum += nums[i];
        }
        for (int i = 0; i < length; i++) {
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
            rightSum -= nums[i + 1];
        }
        return -1;
    }
};

//No.705
class MyHashSet {
private:
    vector<list<int>> hashSet;
    static const int size = 1069; //Prime number
public:
    /** Initialize your data structure here. */
    MyHashSet() : hashSet(size) {}

    void add(int key) {
        if (contains(key)) return;
        hashSet[key % size].emplace_back(key);
    }

    void remove(int key) {
        auto &li = hashSet[key % size];
        for (auto iter = li.begin(); iter != li.end(); ++iter) {
            if (*iter == key) {
                li.erase(iter);
                break;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto &li = hashSet[key % size];
        return any_of(li.begin(), li.end(), [key](int t) { return t == key; });
    }
};

//No.706
class MyHashMap {
private:
    vector<list<pair<int, int>>> hashSet;
    static const int size = 1069; //Prime number
public:
    /** Initialize your data structure here. */
    MyHashMap() : hashSet(size) {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &li = hashSet[key % size];
        for (auto &p : li) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        li.emplace_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &li = hashSet[key % size];
        for (auto &p : li) {
            if (p.first == key) return p.second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &li = hashSet[key % size];
        for (auto iter = li.begin(); iter != li.end(); ++iter) {
            if (iter->first == key) {
                li.erase(iter);
                return;
            }
        }
    }
};

int main() {
}