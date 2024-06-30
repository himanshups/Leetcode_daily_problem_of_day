class DisjointSetUnion {
    private:
        vector<int> parent;
        vector<int> rank;
        int components;

    public:
        DisjointSetUnion(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1);
            components = n;
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }
    
        int find(int x) {
            if (x == parent[x]) 
                return x;
            return parent[x] = find(parent[x]);
        }

        void unionSets(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) 
                return;

            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            components--;
        }
    
        bool isSingleComponent() {
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        auto compare = [&](vector<int>& edge1, vector<int>& edge2) {
            return edge1[0] > edge2[0];
        };
        
        sort(begin(edges), end(edges), compare);
        DisjointSetUnion Alice(n);
        DisjointSetUnion Bob(n);
        
        int addedEdges = 0;
        
        for (auto &edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            if (type == 3) {
                bool added = false;
                
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.unionSets(u, v);
                    added = true;
                }
                
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.unionSets(u, v);
                    added = true;
                }
                
                if (added) {
                    addedEdges++;
                }
                
            } else if (type == 2) {
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.unionSets(u, v);
                    addedEdges++;
                }
            } else {
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.unionSets(u, v);
                    addedEdges++;
                }
            }
        }
        
        if (Alice.isSingleComponent() && Bob.isSingleComponent()) {
            return edges.size() - addedEdges;
        }
        
        return -1;
    }
};
