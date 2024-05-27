class Solution {
public:
    int maxCount=0;
    int specialArray(vector<int>& nums) {
        int x = 0;
        while(x<=nums.size()){
           int count=0;
            for(int i:nums){
                if(i>=x) count++;
            }
            if(count==x){
                return x;
            }
            x++;
        }
        return -1;
    }
};
