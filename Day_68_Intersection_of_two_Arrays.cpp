class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        vector<int> result;
        for (int i = 0, j = 0; i < m && j < n;) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return result;
    }
};
