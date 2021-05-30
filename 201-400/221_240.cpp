#include <cctype>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int curr_224 = 0;
    //递归
    int calculate_224(const string &s) {
        int length = s.length(), result = 0, sign = 1;
        for (; curr_224 < length; ++curr_224) {
            switch (s[curr_224]) {
                case '+':
                    sign = 1;
                    break;
                case '-':
                    sign = -1;
                    break;
                case '(':
                    curr_224++;
                    result += sign * calculate_224(s);
                    break;
                case ' ':
                    break;
                case ')':
                    return result;
                default: {
                    int num = 0;
                    while (curr_224 < length && isdigit(s[curr_224])) {
                        num *= 10;
                        num += s[curr_224] - '0';
                        curr_224++;
                    }
                    curr_224--;
                    result += sign * num;
                }
            }
        }
        return result;
    }


    int calculate_227(string s) {
        int length = s.length(), result = 0, sign = 1, temp = 0, op = 0;
        for (int i = 0; i < length; ++i) {
            switch (s[i]) {
                case '-':
                    sign = -1;
                case '+':
                    result += temp;
                    break;
                case '*':
                    op = 1;
                    break;
                case '/':
                    op = 2;
                    break;
                case ' ':
                    break;
                default: {
                    int num = 0;
                    while (i < length && isdigit(s[i])) {
                        num *= 10;
                        num += s[i] - '0';
                        i++;
                    }
                    i--;
                    if (op == 1)
                        temp *= num;
                    else if (op == 2)
                        temp /= num;
                    else
                        temp = sign * num;
                    op = 0;
                    sign = 1;
                }
            }
        }
        return result + temp;
    }

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

    bool isPowerOfTwo_231(int n) { return n > 0 && !(n & (n - 1)); }
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