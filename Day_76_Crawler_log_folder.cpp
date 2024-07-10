class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(auto &i: logs){
            if(i=="../"){
                if(depth==0) depth=0;
                else depth--;
            }
            else if(i=="./") continue;
            else depth++;
        }
        return depth;
    }
};
