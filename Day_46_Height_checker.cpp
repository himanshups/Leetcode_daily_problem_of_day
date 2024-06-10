
// Approach 1 - Sorting method - O(nlogn) time

class Solution {
public:
    int heightChecker(vector<int>& heights) { 
        int n = heights.size();
        vector<int> arr;
        arr=heights;
        sort(heights.begin(),heights.end());

        int count = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]!=heights[i]) count++;
        }
        return count;
    }
};

// Approach 2 - Using Counting sort - O(n) 

class Solution {
public:
    int heightChecker(vector<int>& heights) {
int max_height = *max_element(heights.begin(), heights.end());
    
    // Initialize a frequency array with zeros, with size of max_height + 1
    vector<int> count(max_height + 1, 0);
    
    // Count the frequency of each height
    for (int height : heights) {
        count[height]++;
    }
    
    // Reconstruct the expected array using the frequency array
    int index = 0;
    vector<int> expected(heights.size());
    for (int height = 0; height <= max_height; height++) {
        while (count[height] > 0) {
            expected[index++] = height;
            count[height]--;
        }
    }
    
    // Count the number of indices where heights[i] != expected[i]
    int mismatch_count = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] != expected[i]) {
            mismatch_count++;
        }
    }
    
    return mismatch_count;
    }
};
