class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Get the size of the intervals vector
        int n = intervals.size();
        
        // Initialize a vector to store the merged intervals
        vector<vector<int>> ans;
        
        // Iterate through each interval in the intervals vector
        for(int i = 0; i < n; i++) {
            // If the end of the current interval is less than the start of the new interval,
            // there is no overlap, so add the current interval to the answer vector
            if(intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            }
            // If the start of the current interval is greater than the end of the new interval,
            // it means there won't be any more overlaps, so add the new interval and update it to the current one
            else if(intervals[i][0] > newInterval[1]) {
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            // If there's an overlap between the current interval and the new interval,
            // merge them by updating the start and end of the new interval
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        // Add the last merged interval to the answer vector
        ans.push_back(newInterval);
        
        // Return the merged intervals
        return ans;
    }
};
