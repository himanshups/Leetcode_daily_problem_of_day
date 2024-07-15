#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr, right(nullptr)) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int, vector<pair<int, int>>> parentToChildrenMap;
        set<int> potentialRoots;

        populateMaps(descriptions, parentToChildrenMap, potentialRoots);
        int rootValue = findRoot(potentialRoots, descriptions);
        TreeNode *root = new TreeNode(rootValue);

        buildTree(root, parentToChildrenMap);

        return root;
    }

private:
    void populateMaps(const vector<vector<int>> &descriptions, 
                      unordered_map<int, vector<pair<int, int>>> &parentToChildrenMap, 
                      set<int> &potentialRoots) {
        for (const auto &desc : descriptions) {
            parentToChildrenMap[desc[0]].emplace_back(desc[1], desc[2]);
            potentialRoots.insert(desc[0]);
        }

        for (const auto &desc : descriptions) {
            if (potentialRoots.find(desc[1]) != potentialRoots.end()) {
                potentialRoots.erase(desc[1]);
            }
        }
    }

    int findRoot(const set<int> &potentialRoots, const vector<vector<int>> &descriptions) {
        for (const auto &root : potentialRoots) {
            return root;
        }
        return -1; // Return a dummy value, should not reach here if input is valid
    }

    void buildTree(TreeNode *root, const unordered_map<int, vector<pair<int, int>>> &parentToChildrenMap) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode *currentNode = nodeQueue.front();
                nodeQueue.pop();

                int currentNodeValue = currentNode->val;

                if (parentToChildrenMap.find(currentNodeValue) != parentToChildrenMap.end()) {
                    for (const auto &child : parentToChildrenMap.at(currentNodeValue)) {
                        TreeNode *childNode = new TreeNode(child.first);

                        if (child.second == 1) {
                            currentNode->left = childNode;
                        } else {
                            currentNode->right = childNode;
                        }

                        nodeQueue.push(childNode);
                    }
                }
            }
        }
    }
};
