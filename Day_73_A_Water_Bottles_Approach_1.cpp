class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        while(numBottles>=numExchange){
            int  num = numBottles/numExchange;
            sum+=num;
            numBottles=numBottles%numExchange+num;

        }
        return sum;
    }
};
