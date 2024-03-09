class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int low1 = 0, low2 = 0;
        int n = nums1.size(), m = nums2.size();

        while (low1 < n && low2 < m) {
            if (nums1[low1] == nums2[low2]) 
                return nums1[low1];
            else if (nums1[low1] > nums2[low2]) 
                low2++;
            else 
                low1++;
        }

        return -1;
    }
};
