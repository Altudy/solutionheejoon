class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        recur(root, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void recur(TreeNode* node, int level) {
        if(!node) return;
        if(ans.size() <= level) ans.push_back({});
        ans[level].emplace_back(node->val);
        recur(node->left, level+1);
        recur(node->right, level+1);
    }
};
////////////////////////////////////////////////////
// my solution 2

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> layer;
        if(!root) return ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        pair<TreeNode*, int> cur;
        int level = 0;

        while(!q.empty())
        {
            cur = q.front(); q.pop();
            if(!cur.first) continue;
            
            q.push({cur.first->left, cur.second+1});
            q.push({cur.first->right, cur.second+1});
            
            if(cur.second == level) {
                layer.push_back(cur.first->val);
            }
            else {
                ans.push_back(layer);
                layer.clear();
                layer.push_back(cur.first->val);
                level++;
            }
        }
        ans.push_back(layer);
        return ans;
    }
};
