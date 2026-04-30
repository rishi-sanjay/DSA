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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;
     ListNode *odd=head;
     if(odd->next==nullptr) {
     return head;}
     ListNode *even;
     ListNode *rem=odd->next;
     while(odd->next){
        even=odd->next;
        if(even->next==nullptr){
            even->next=nullptr;
            break;
        }
        ListNode *aage=even->next;
        odd->next=aage;
        odd=odd->next;
        even->next=odd->next;
     }
     odd->next=rem;
     return head;
    }
};