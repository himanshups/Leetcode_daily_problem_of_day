class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0;
        long maxReach = 0;
        long arrayPatch = 0;

        while(maxReach<n){
            if(i<nums.size() && nums[i]<=maxReach+1){
                maxReach+=nums[i];
                i++;
            }
            else{
                maxReach+=(maxReach+1);
                arrayPatch++;
            }
        }
        return arrayPatch;
    }
};
