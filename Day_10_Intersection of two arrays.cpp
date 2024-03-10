class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j= 0, n1 = nums1.size(), n2 = nums2.size();
        while(i<n1 &&  j<n2){
            if( nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                while(i<n1 && ans.back() == nums1[i])i++;
                while(j<n2 && ans.back() == nums2[j])j++;
            }
            else if( nums1[i]>nums2[j])j++;
            else i++;    
        }
        return ans;
    }
};
