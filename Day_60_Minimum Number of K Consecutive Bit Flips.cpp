class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int totalFlips = 0;
        vector<bool> flipIndicator(n, false);
        int currentFlipEffect = 0;

        for(int i = 0; i < n; i++) {
            // Check if the effect of the flip at position (i-k) should be removed
            if(i >= k && flipIndicator[i - k]) {
                currentFlipEffect--;                     
            }
            
            // If the current number needs to be flipped
            if(currentFlipEffect % 2 == nums[i]) {
                // If flipping k bits from the current position exceeds the array bounds, return -1
                if(i + k > n) {
                    return -1;
                }
                // Apply the flip effect
                currentFlipEffect++;
                flipIndicator[i] = true;
                totalFlips++;
            }
        }

        return totalFlips;
    }
};
