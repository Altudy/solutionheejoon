class Solution {
public:
    bool chk(TreeNode* node, long min, long max) {
        if(!node) return true;
        if(node->val <= min || node->val >= max) return false;
        return (chk(node->left, min, node->val) && chk(node->right, node->val, max));
    }

    bool isValidBST(TreeNode* root) {
        return chk(root, LONG_MIN, LONG_MAX);
    }
};
