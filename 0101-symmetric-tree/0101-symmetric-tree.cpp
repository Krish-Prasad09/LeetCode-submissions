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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        // while(!q.empty()){
        //     int sz=q.size();
        //     stack<int> st;
        //     while(sz--){
        //         auto node=q.front();
        //         q.pop();
        //         if(node->left){
        //             q.push(node->left);
        //             if(st.empty() || st.top()  !=node->left->val) st.push(node->left->val);
        //             else if(st.top() ==node->left->val){
        //                 st.pop();
        //             }
        //         }
        //         else{
        //             st.push(-1);
        //         }
        //         if(node->right){
        //             q.push(node->right);
        //             if(st.empty() || st.top() !=node->right->val) st.push(node->right->val);
        //             else if(st.top() ==node->right->val){
        //                 st.pop();
        //             }
        //         }
        //         else{
        //             st.push(-1);
        //         }
        //     }
        //     if(!st.empty()) return false;

        // }


        while(!q.empty()){
    int sz = q.size();
    vector<int> level; // Use a vector to store the level's layout
    
    while(sz--){
        auto node = q.front();
        q.pop();
        
        if(node->left){
            q.push(node->left);
            level.push_back(node->left->val);
        } else {
            level.push_back(-101); // Use -101 to avoid clashing with valid values
        }
        
        if(node->right){
            q.push(node->right);
            level.push_back(node->right->val);
        } else {
            level.push_back(-101); 
        }
    }
    
    // Check if the current level is symmetric (a palindrome)
    int l = 0, r = level.size() - 1;
    while(l < r){
        if(level[l++] != level[r--]) return false;
    }
}
        return true;
    }
};