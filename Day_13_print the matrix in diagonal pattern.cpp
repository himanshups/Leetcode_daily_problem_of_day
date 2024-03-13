class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int i = 0,j=n,lsum=0,rsum=n;
        while(i<j){
            if(lsum<rsum)i++,lsum+=i;
            else j--,rsum+=j;
        }
        if(lsum == rsum) return i;
        return -1;
    }
};
