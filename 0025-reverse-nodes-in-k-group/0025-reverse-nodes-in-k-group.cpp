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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* temp=dummy;
        while(true){
            ListNode* end=temp;
            for(int i=0;i<k;i++){
                end=end->next;
                if(end==nullptr){
                    return dummy->next;
                }
            }

            ListNode* after=end->next;

            ListNode* curr=temp->next;
            ListNode* last=after;
            while(curr!=after){
                ListNode* next=curr->next;
                curr->next=last;
                last=curr;
                curr=next;
            }

            ListNode* first=temp->next;
            temp->next=end;
            temp=first;
        }
    }
};