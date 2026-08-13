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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* secondHalfHead=reverseLL(slow);
        ListNode* firstHalfPtr=head;
        ListNode* secondHalfPtr=secondHalfHead;

        while (secondHalfPtr) {
            if (firstHalfPtr->val != secondHalfPtr->val) {
                return false;
            }
            firstHalfPtr = firstHalfPtr->next;
            secondHalfPtr = secondHalfPtr->next;
        }

        return true;
    }
};