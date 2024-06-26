class Solution {
public:
    // Function to perform in-order traversal and store values in a vector
    void inOrderTraversal(TreeNode* node, vector<int>& values) {
        if (!node)
            return;

        inOrderTraversal(node->left, values);
        values.push_back(node->val);
        inOrderTraversal(node->right, values);
    }

    // Function to construct a balanced BST from a sorted vector
    TreeNode* buildBalancedBST(int start, int end, vector<int>& values) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* newNode = new TreeNode(values[mid]);

        newNode->left  = buildBalancedBST(start, mid - 1, values);
        newNode->right = buildBalancedBST(mid + 1, end, values);

        return newNode;
    }

    // Main function to balance the BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;
        inOrderTraversal(root, sortedValues);

        return buildBalancedBST(0, sortedValues.size() - 1, sortedValues);
    }
};
