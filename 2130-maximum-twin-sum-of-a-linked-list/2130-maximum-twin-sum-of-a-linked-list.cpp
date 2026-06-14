/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int pairSum(ListNode* head) {
        ListNode* node=head;
        vector<int> ans1;
        while(node){
            ans1.push_back(node->val);
            node=node->next;
        }
        vector<int> ans2=ans1;
        reverse(ans2.begin(),ans2.end());
        int n=ans1.size();
        vector<int> sum(n,0);
        int maxi=0;
        for(int i=0; i<n; i++){
            sum[i]=ans1[i]+ans2[i];
            maxi=max(maxi,sum[i]);
        }
        return maxi;
    }
};