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
       ListNode *dumm=new ListNode(0);
       dumm->next=head;
       ListNode *pre=dumm;
       while(pre->next && pre->next->next){
        ListNode *one=pre->next;
        ListNode *se=one->next;
        one->next=se->next;
        se->next=one;
        pre->next=se;
        pre=one;
       } 
       return dumm->next;
    }
};