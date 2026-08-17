/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;

        // Build bidirectional adjacency list
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                adj[node].push_back(node->left);
                adj[node->left].push_back(node);
                q.push(node->left);
            }

            if(node->right) {
                adj[node].push_back(node->right);
                adj[node->right].push_back(node);
                q.push(node->right);
            }
        }

        // BFS from target
        vector<int> ans;
        unordered_map<TreeNode*, bool> vis;

        queue<pair<TreeNode*, int>> q2;
        q2.push({target, 0});
        vis[target] = true;

        while(!q2.empty()) {
            auto [node, dist] = q2.front();
            q2.pop();

            if(dist == k) {
                ans.push_back(node->val);
                continue;
            }

            for(auto x : adj[node]) {
                if(!vis[x]) {
                    vis[x] = true;
                    q2.push({x, dist + 1});
                }
            }
        }

        return ans;
    }
};