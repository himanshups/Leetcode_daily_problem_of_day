class Solution {
private:
    void dfs(string& s, int start, vector<string>& temp, vector<vector<string>>& soln){
        int n = s.length();
        if(start == n) soln.push_back(temp);
        else{
            for(int i = start; i<n; i++){
                if(isPalindrom(s,start,i)){
                    temp.push_back(s.substr(start,i-start+1));
                    dfs(s,i+1, temp, soln);
                    temp.pop_back();
                }
            }
        }
    }

    bool isPalindrom(string& s, int i , int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> soln;
        dfs(s,0,temp,soln);

        return soln;
    }
};
