class Solution {
public:
    int maxDepth(TreeNode* root) {
        ans=0;
        dfs(root, 1);
        return ans;
    }
private:
    int ans;
    void dfs(TreeNode* node, int depth) {
        if(!node) return;
        if(depth > ans) ans = depth;
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);        
    }
};
