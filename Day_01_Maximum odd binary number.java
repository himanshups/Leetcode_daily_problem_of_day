class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        // initializing new string all of 0
        for(int i = 0;i<n;i++){
            ans.append('0');
        }
        // count total no of ones in string
        int count_one = 0;
        for(char character : s.toCharArray()){
            if(character=='1') count_one++;
        }
        // set no of one's from Most Significant Bit 
        int j = 0;
        while(count_one>1){
            ans.setCharAt(j,'1');
            j++;
            count_one--;
        }
        //asigning last significant bit to 1 - making it odd number
        ans.setCharAt(n-1,'1');

        //returning string
        return ans.toString();
    }

}
