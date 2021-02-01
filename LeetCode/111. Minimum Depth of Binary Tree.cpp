typedef pair<TreeNode*, int> pti;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pti> q;
        q.push({root, 1});
        
        pti top;
        while(!q.empty()) {
            top = q.front();
            q.pop();

            if(!top.first->left && !top.first->right) return top.second;
            if(top.first->left) q.push({top.first->left, top.second + 1});
            if(top.first->right) q.push({top.first->right, top.second + 1});
        }
        return 0;
    }
};
////////////////////////////////////////////////////////////////////////////
// best solution

class Solution {
public:
int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
	
        int min_depth = INT_MAX;
	
        if(root->left)
            min_depth = min(min_depth, minDepth(root->left));
        if(root->right)
            min_depth = min(min_depth, minDepth(root->right));
        return 1 + min_depth;
    }
};
