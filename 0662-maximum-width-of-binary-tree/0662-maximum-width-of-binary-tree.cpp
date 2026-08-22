class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;

        long long maxi = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()){

            int size = q.size();
            long long minidx = q.front().second;

            long long first = 0, last = 0;

            for(int i = 0; i < size; i++){

                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                long long currIdx = curr.second - minidx;

                if(i == 0) first = currIdx;
                if(i == size - 1) last = currIdx;

                if(node->left)
                    q.push({node->left, 2*currIdx + 1});

                if(node->right)
                    q.push({node->right, 2*currIdx + 2});
            }

            maxi = max(maxi, last - first + 1);
        }

        return maxi;
    }
};