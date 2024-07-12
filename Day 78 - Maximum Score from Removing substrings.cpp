#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(string& s, string si, int val) {
        int points = 0;
        int n = s.size();
        stack<char> st;  // Use stack to help in removing substrings
        
        // Iterate through the string
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                // Check if the current character and the top of the stack form the target substring
                if (s[i] == si[1] && st.top() == si[0]) {
                    st.pop();
                    points += val;
                } else {
                    st.push(s[i]);
                }
            }
        }
        
        // Reconstruct the string from the stack
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        
        return points;
    }
    
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        
        // If x is less than y, swap the substrings and their values
        if (x < y) {
            swap(s1, s2);
            swap(x, y);
        }
        
        // Remove the more valuable substring first
        return maxPoints(s, s1, x) + maxPoints(s, s2, y);
    }
};

int main() {
    Solution sol;
    string s = "cabxbae";
    int x = 4;
    int y = 5;
    cout << sol.maximumGain(s, x, y) << endl;  // Output: 9
    return 0;
}
