class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        for(int i = 0; i < n ; i++){
            int a = arr[i];
            for(int k = i + 1; k < n ; k++){
                a ^= arr[k];
                if(a == 0)
                    res += (k - i); 
            }
        }
        return res;   
    }
};
