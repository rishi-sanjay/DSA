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
    ListNode* swapPairs(ListNode* head) {
       if(head==nullptr || head->next==nullptr) return head;
       ListNode *pa=head;
       ListNode* temp=head->next;
       ListNode* rem=nullptr;
       ListNode* fa=nullptr;
       bool one=1;
       while(temp !=nullptr){
        if(temp !=nullptr) fa=temp->next;
        else break;
        temp->next=pa;
        if(one){
            head=temp;
            pa->next=rem;
            rem=pa;
            one=0;
        }else{
            rem->next=temp;
            rem=pa;
        }
        if(fa==nullptr) {
            rem->next=nullptr;
            break;
        }
        pa=fa;
        if(fa->next==nullptr){
            rem->next=pa;
            break;
        }else
           temp=pa->next;
       } 
       return head;
    }
};