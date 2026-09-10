/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans=0;
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        int sum=root->val;
        auto p1=solve(root->left);
        auto p2=solve(root->right);
        sum+=p1.first;
        sum+=p2.first;
        int len=1;
        len+=p1.second;
        len+=p2.second;
        if((sum/len) ==root->val) ans++;
        return {sum,len};
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return ans;
    }
};