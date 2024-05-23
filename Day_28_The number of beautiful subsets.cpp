class Solution {
public:
    int count;
    int K;
    void dfs(vector<int>& nums,int idx, unordered_map<int,int>&mp){
        if(idx==nums.size()){
            count++;
            return;
        }
        //not_take
        dfs(nums,idx+1,mp);
        //checking if we can take it or not
        if(!mp[nums[idx]-K] && !mp[nums[idx]+K]){
            mp[nums[idx]]++;
            dfs(nums,idx+1,mp);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        count=0;
        K=k;
        unordered_map<int,int> mp;
        dfs(nums,0,mp);
        return count-1;
    }
};
