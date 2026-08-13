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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverseLL(head);
        if(n==1){
            ListNode* newHead=head->next;
            delete head;
            head=newHead;
        }
        else{
            ListNode* curr=head;
            for(int i=1;i<n-1;i++){
                curr=curr->next;
            }

            ListNode* nodeToDel=curr->next;
            curr->next=curr->next->next;
            delete nodeToDel;
        }
        head=reverseLL(head);
        return head;
    }
};