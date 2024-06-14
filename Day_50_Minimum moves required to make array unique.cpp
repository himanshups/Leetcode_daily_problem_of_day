//Approach - 01 using counting sort = O(n) 

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxElement = 0;
        int count = 0;

        maxElement = *max_element(begin(nums),end(nums));
        vector<int> frequency(n+maxElement);
        for(int num:nums){
            frequency[num]++;
        }
        int m = frequency.size();
        for(int i = 0;i<m;i++){
            if(frequency[i]<=1) continue;
            int extra = frequency[i]-1;
            frequency[i+1]+=extra;
            frequency[i]=1;
            count+=extra;
        }
        return count;
    }
};

// Approach 2 - Using Sorting - O(nlogn)

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int count = 0;

        for(int i = 1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                count += nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return count;
    }
};
