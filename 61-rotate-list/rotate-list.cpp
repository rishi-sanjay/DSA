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
    int sizee(ListNode* head){
          int count=0;
          ListNode *temp=head;
          while(temp){
            temp=temp->next;
            count++;
          }
          return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
    
        int sz=sizee(head);
        if(sz==0) return head;
        if(k==0) return head;
        ListNode *temp=head;
        while(temp->next){
            temp=temp->next; 
        }
        int p=k%sz;
        p=sz-p;
        ListNode *neww=head;
        while(p>1){
            neww=neww->next;
            p--;
        }
        
        temp->next=head;
        head=neww->next;
        neww->next=NULL;
   return head;
    }
};