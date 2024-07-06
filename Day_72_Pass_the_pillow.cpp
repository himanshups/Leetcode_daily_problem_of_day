class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        int direction = 1;
        while(time-->0){
            i+=direction;
            if(i==1 || i==n){
                direction = direction*-1;
            }
        }
        return i;
    }
};
