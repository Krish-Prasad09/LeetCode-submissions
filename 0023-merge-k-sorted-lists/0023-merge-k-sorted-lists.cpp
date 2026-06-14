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
 class Compare {
public:
    // Comparator to order ListNode pointers based on node values
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(auto list:lists){
            if(list) pq.push(list);
        }
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(!pq.empty()){
            ListNode* smallest=pq.top();
            pq.pop();
            tail->next=smallest;
            tail=smallest;
            if (smallest->next != NULL)
                pq.push(smallest->next);
            }
        return dummy->next;
    }
};