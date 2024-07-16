class Solution {
public:
    TreeNode* findLowestCommonAncestor(TreeNode* root, int value1, int value2) {
        if (!root)
            return nullptr;
        
        if (root->val == value1 || root->val == value2)
            return root;
        
        TreeNode* leftAncestor = findLowestCommonAncestor(root->left, value1, value2);
        TreeNode* rightAncestor = findLowestCommonAncestor(root->right, value1, value2);
        
        if (leftAncestor && rightAncestor)
            return root;
        
        return leftAncestor ? leftAncestor : rightAncestor;
    }

    bool searchPath(TreeNode* root, int target, string& path) {
        if (!root)
            return false;

        if (root->val == target)
            return true;

        path.push_back('L');
        if (searchPath(root->left, target, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (searchPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    string constructPath(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLowestCommonAncestor(root, startValue, destValue);
        
        string pathToStart = "";
        string pathToDest = "";

        searchPath(lca, startValue, pathToStart);
        searchPath(lca, destValue, pathToDest);

        string result = string(pathToStart.size(), 'U') + pathToDest;

        return result;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        return constructPath(root, startValue, destValue);
    }
};
