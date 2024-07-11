class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk; // Stack to store the indices of '('
        string res;     // Result string
        
        for (char c : s) {
            if (c == '(') {
                stk.push(res.length()); // Push the index of '('
            } else if (c == ')') {
                int start = stk.top(); // Get the index of the last unmatched '('
                stk.pop();
                reverse(res.begin() + start, res.end()); // Reverse the substring
            } else {
                res += c; // Append characters to the result
            }
        }
        
        return res;
    }
};
