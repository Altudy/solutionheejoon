class Solution {
public:
    bool isSymmetric(TreeNode* root) {        
        if(!root) return true;
        return compare(root->left, root->right);        
    }
    bool compare(TreeNode* n1, TreeNode* n2) {
        if(!n1 && !n2) return true;
        if(!n1 || !n2) return false;
        if(n1->val != n2->val) return false;
        return compare(n1->left, n2->right) && compare(n1->right, n2->left);
    }
};
