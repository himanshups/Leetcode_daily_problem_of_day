class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size();
    int count = 0;
    int currentSum = 0;

    mp[0] = 1; // Initialize for the case when subarray itself sums to k

    for (int i = 0; i < n; ++i) {
        currentSum += (nums[i] % 2); // Increment current sum by 1 if odd, 0 if even

        // Check if there's a prefix subarray that sums to currentSum - k
        if (mp.find(currentSum - k) != mp.end()) {
            count += mp[currentSum - k];
        }

        // Update the count of the currentSum in the prefixSumCount map
        mp[currentSum]++;
    }

    return count;

    }
};
