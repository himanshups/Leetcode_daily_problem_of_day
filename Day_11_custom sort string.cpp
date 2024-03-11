class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        string ans = "";
        for (char c : order) {
            if (counts.find(c) != counts.end()) {
                ans += string(counts[c], c);
                counts.erase(c);
            }
        }

        for (auto& [c, count] : counts) {
            ans += string(count, c);
        }

        return ans;
    }
};
