class Solution {
public:
    // Approach 1 - Use backtracking to generate subsets
    // void solve(vector<int>&nums, int i, vector<int>& currSubset,vector<vector<int>>&subSets){
    //     if(i==nums.size()){
    //             subSets.push_back(currSubset);
    //             return;
    //         }
    //     currSubset.push_back(nums[i]);
    //     solve(nums,i+1,currSubset,subSets);
    //     currSubset.pop_back();
    //     solve(nums,i+1,currSubset,subSets);
    // }

    //Approach 2 - Using optimal backtracking
    int solve(int i,vector<int>&nums, int Xor){
        if(i==nums.size()){
            return Xor;
        }
        int include = solve(i+1,nums,nums[i]^Xor);
        int exclude = solve(i+1,nums,Xor);

        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        // Approach 1 - Use backtracking to generate subsets
        // vector<vector<int>> subsets;
        // vector<int> currSubset;
        // solve(nums,0,currSubset,subsets);
        // int result = 0;
        // for(auto& currSubset:subsets){
        //     int Xor = 0;
        //     for(int num:currSubset){
        //         Xor^=num;
        //     }
        //     result+=Xor;
        // }
        // return result;

        //Approach 2: Using optimal backtracking
        return solve(0,nums,0);


        // //Approach 3 - Observation (hard) level
        // int temp=0;
        // int n = nums.size();
        // for(int i:nums)
        // //finding OR sum of all elements
        //     temp|=i;
        // //appending n-1 0 at the end of the XOR sum
        // return temp<<n-1;
    }

    
};
