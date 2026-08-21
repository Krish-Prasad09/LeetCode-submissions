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
int f(TreeNode*root,int &idk){
    if(!root) return 0;
    int lz=f(root->left,idk)+1;
    int rz=f(root->right,idk)+1;
    if(abs(lz-rz)>1) idk=0;
    return max(lz,rz);
}
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!(root->left) && !(root->right)) return true;
        int idk=-1;
        auto s=f(root,idk);
        return idk==-1;
    }
};