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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* node=head;
        int prev=-1;
        int i=0;
        while(node){
            int a=node->val;
            ListNode* nxtnode=node->next;
            int b=INT_MAX;  
            if(nxtnode) b=nxtnode->val;

            if(nxtnode && i!=0 && ( (a>prev && a>b) || (a<prev && a<b) ) ){
                ans.push_back(i);
            }
            prev=node->val;
            node=node->next;
            i++;
        }
        int n=ans.size();
        if(n==0 || n==1) return {-1,-1};
        int maxi=abs(ans.back() -ans.front()) ,mini=INT_MAX;
        for(int i=0; i<n; i++){
            int a = INT_MAX;
            int b = INT_MAX;

            if(i > 0)
                a = ans[i] - ans[i-1];

            if(i+1 < n)
                b = ans[i+1] - ans[i];

            mini = min(mini, min(a, b));
        }
        return {mini,maxi};
    }
};