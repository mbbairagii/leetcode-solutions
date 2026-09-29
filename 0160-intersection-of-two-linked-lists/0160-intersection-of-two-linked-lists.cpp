/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        ListNode* temp=headA;
        while(temp!=nullptr){
            lenA++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=nullptr){
            lenB++;
            temp=temp->next;
        }

        ListNode* a= headA;
        ListNode* b=headB;
        if(lenA>lenB){
            int diff=lenA-lenB;
            while(diff--){
                a=a->next;
            }
        }
        else{
            int diff=lenB-lenA;
            while(diff--){
                b=b->next;
            }
        }

        while(a!=b){
            a=a->next;
            b=b->next;
        }

        return a;
    }
};