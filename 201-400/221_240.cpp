#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges_228(vector<int> &nums) {
        vector<string> result;
        int length = nums.size();
        if (length == 0)
            return result;
        int record = 0;
        for (int i = 0; i < length; i++) {
            if (i + 1 == length || nums[i + 1] != 1 + nums[i]) {
                if (record == i)
                    result.emplace_back(to_string(nums[record]));
                else
                    result.emplace_back(to_string(nums[record]) + "->" + to_string(nums[i]));
                record = i + 1;
            }
        }
        return result;
    }
};

//No.232
class MyQueue {
private:
    //入队的元素放入normal中（正常的先进后出栈），从reversed中出队（顺序颠倒，相当于先进先出）
    //从reversed出队一个元素，如果reversed中没有元素了，需要把normal中的元素都倒入reversed中
    stack<int> normal;
    stack<int> reversed;

    /** pop from a, then push into b */
    void popTo(stack<int> &from, stack<int> &to) {
        while (!from.empty()) {
            to.push(from.top());
            from.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        normal.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (reversed.empty())
            popTo(normal, reversed);
        int top = reversed.top();
        reversed.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (reversed.empty())
            popTo(normal, reversed);
        return reversed.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return normal.empty() && reversed.empty();
    }
};

int main()
{
}