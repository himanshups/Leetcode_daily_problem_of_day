#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Initialize the answer vector with sets for each node
        vector<set<int>> ans(n);
        // Initialize the in-degree vector for each node
        vector<int> indegree(n, 0);

        // Create a mapping from parents to their children
        unordered_map<int, vector<int>> parent_to_kids;
        for (const auto& edge : edges) {
            int parent = edge[0];
            int kid = edge[1];
            // Add parent to the set of ancestors for the kid
            ans[kid].insert(parent);
            // Append the kid to the list of children for the parent
            parent_to_kids[parent].push_back(kid);
            // Increment the in-degree of the kid
            indegree[kid]++;
        }
        
        // Initialize the deque with nodes having zero in-degree
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                dq.push_back(i);
            }
        }
        
        // Process nodes in topological order
        while (!dq.empty()) {
            int parent = dq.front();
            dq.pop_front();
            for (int kid : parent_to_kids[parent]) {
                // Update the kid's ancestors with all ancestors of the parent
                ans[kid].insert(ans[parent].begin(), ans[parent].end());
                // Decrement the in-degree of the kid
                indegree[kid]--;
                // If the in-degree becomes zero, add the kid to the deque
                if (indegree[kid] == 0) {
                    dq.push_back(kid);
                }
            }
        }
        
        // Convert each set of ancestors to a sorted vector
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ans[i].begin(), ans[i].end());
            sort(result[i].begin(), result[i].end());
        }

        return result;
    }
};
