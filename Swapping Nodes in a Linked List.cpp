// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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
    ListNode* swapNodes(ListNode* head, int k) {
        // Logic: if we reach k steps, that means we need to go n-k more steps from start and we will reach at node2
        ListNode* nd1=NULL, *nd2=NULL;
        ListNode* temp=head;

        while(temp) {
            if(nd2 != NULL) nd2=nd2->next;

            k--;
            if(k == 0){
                nd1=temp; 
                nd2=head;
            }
            temp=temp->next;
        }

        swap(nd1->val, nd2->val);
        return head;
    }
};
