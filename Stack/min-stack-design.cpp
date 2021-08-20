// LeetCode: https://leetcode.com/problems/min-stack/submissions/

// Time Complexity: O(1) for all the operations
// Space Complexity: O(n)


class MinStack {
public:
    stack<long> s;
    long min;
    MinStack() {
        while(s.empty() == false)
            s.pop();
        min = INT_MAX;
    }

    void push(int val) {
        long v = val;
        if(s.empty()) {
            s.push(v);
            min = v;
        } else {           
            if(val < min) {
                s.push(2*v - min);
                min = v;
            } else {
                s.push(v);
            }
        }
    }

    void pop() {
        long p = s.top();
        s.pop();
        if(p < min) {
            min = 2*min - p;
        }
    }

    int top() {
        long t = s.top();
        if(t < min) {
            return min;
        }
        return t;
    }
    
    int getMin() {
        return min;
    }
};