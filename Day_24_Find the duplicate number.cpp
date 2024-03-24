class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr(nums.size(), 0);
        for(auto num : nums){
            arr[num]++;
            if(arr[num]==2){
                return num;
            }
        }
        return 0;
    }
};
