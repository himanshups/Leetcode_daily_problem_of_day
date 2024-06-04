class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int result  = 0;
        int oddFrq  = 0;

        for(char &ch : s) {
            mp[ch]++;

            if(mp[ch] % 2 != 0) {
                oddFrq++;
            } else {
                oddFrq--;
            }
        }

        if(oddFrq > 0) {
            return n - oddFrq + 1;
        }

        return n;
    }
};
