class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_take = 0;
        //1) finding the xor of value;
        for(int &i:nums) xor_take^=i;

        //taking mask value;
        long mask = xor_take & (-xor_take);

        //make two groups

        int groupa=0,groupb=0;

        for(int &num: nums){
            if(num & mask) groupa^=num;
            else groupb^=num;
        }

        return {groupa, groupb};
    }
};
