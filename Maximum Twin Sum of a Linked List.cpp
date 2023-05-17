// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

// Approach: Reverse LL from Second half and then put 2 pointers, (one at start and second at start of 2nd half), then
// try to iterate uptil second pointer goes nullptr and find maximum answer

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
    ListNode* reverse(ListNode* ptr) {
        ListNode* prev=NULL, *curr=ptr, *n=ptr->next;

        while(curr!=NULL) {
            curr->next=prev;
            prev=curr;
            curr=n;
            if(n!= NULL) n=n->next;
        }
        return prev;
    }
    void reverseFromMid(ListNode* head) {
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast!=NULL && fast->next != NULL) {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp = reverse(slow);
        prev->next=temp;
    }
    int pairSum(ListNode* head) {
        // TC:O(No. of nodes), SC: O(1)
        reverseFromMid(head);

        ListNode* slow=head, *fast=head;
        while(fast!=NULL && fast->next != NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }

        int ans=0;
        ListNode* temp=head;
        while(slow!=NULL) {
            ans = max(ans, temp->val+slow->val);
            temp=temp->next;
            slow=slow->next;
        }

        return ans;
    }
};
