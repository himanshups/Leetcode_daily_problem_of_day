class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int start = 0;
        int end = tokens.length-1;
        int max = 0;
        int current = 0;
        while(start<=end){
            if(power>= tokens[start])
            {
                power-= tokens[start];
                start++;
                current++;
            }
            else if(max>0) {
                power+=tokens[end];
                end--;
                current--;
            }
            else break;
            max = Math.max(max,current);
        }
        return max;
    }
}
