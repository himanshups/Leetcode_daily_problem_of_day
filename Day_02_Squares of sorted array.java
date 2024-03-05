class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int [] ans = new int[n];
        int start = 0;
        int end = n-1;
        int temp = n-1;
        while(temp>=0){
            int p = nums[start]*nums[start];
            int q = nums[end]*nums[end];
            if(p>q){
                ans[temp]=p;
                start++;
            }
            else{
                ans[temp]=q;
                end--;
            }
            temp--;
        }
        return ans;
    }
}
