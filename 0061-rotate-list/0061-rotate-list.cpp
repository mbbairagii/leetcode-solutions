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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* temp=head;
        int count=0;

        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }

        k=k%count;
        if(k==0){
            return head;
        }

        temp=head;
        for(int i=0;i<count-k-1;i++){
            temp=temp->next;
        }

        ListNode* newH=temp->next;
        ListNode* tail=newH;
        while(tail->next!=nullptr){
            tail=tail->next;
        }

        tail->next=head;
        temp->next=nullptr;
        return newH;
    }
};