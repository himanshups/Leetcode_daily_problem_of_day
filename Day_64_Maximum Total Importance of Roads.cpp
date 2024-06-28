class Solution {
public:
    long long maximumImportance(int nodeCount, vector<vector<int>>& roadList) {
        //n = total number of nodes numbered from 0 to n-1
      vector<int> nodeDegrees(nodeCount, 0);

        for(auto &road : roadList) {
            int startNode = road[0];
            int endNode = road[1];

            nodeDegrees[startNode]++;
            nodeDegrees[endNode]++;
        }

        sort(begin(nodeDegrees), end(nodeDegrees)); // ascending order

        long long currentValue = 1;
        long long totalImportance = 0;

        for(int i = 0; i < nodeCount; i++) {
            totalImportance += (nodeDegrees[i] * currentValue);
            currentValue++;
        }

        return totalImportance;
    }
};
