class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int maxi=INT_MIN, c=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            maxi=max(maxi, mp[nums[i]]);
        }
        
        for(auto it: mp){
            if(it.second==maxi)
            c+=it.second;
        }

        return c;
    }
};
