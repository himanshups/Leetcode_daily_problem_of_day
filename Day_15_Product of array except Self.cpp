class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {

        long long sum = 1; 
        int cnt= 0;
        for(auto it: arr){
            if(it)
            sum = sum*it;
        
            if(it==0)cnt++;
        } 
        for(int i =0; i<arr.size(); i++){
            if(arr[i])
            {   if(cnt)arr[i]= 0;
                else
                arr[i] = sum/arr[i]; 
            }
            else if(cnt==1) arr[i]= sum;
            else arr[i] = 0;
        }
        return arr;
        
    }
};
