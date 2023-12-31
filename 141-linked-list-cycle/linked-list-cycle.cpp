/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
        Approach:
        using two pointers slow and fast , iterate if cycle found, then slow and fast will meet
        TC => O(n)
        SC => O(1)
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return false;
        ListNode* fast=head,*slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
          slow = slow->next;
          fast = fast->next->next;
          if(fast==slow)return true;
        }
        return false;
    }
};