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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            ListNode* aage = temp->next;
            if (aage && temp->val == aage->val) {
                ListNode *prev1 = aage;
                while (aage && aage->val == temp->val) {
                    prev1 = aage;
                    aage = aage->next;
                }
                if(prev==nullptr) {
                    head=aage;
                
                }
                if(prev) prev->next = aage;
                temp = aage;
                prev1 = nullptr;
            } else {
                prev = temp;
                temp = aage;
            
            }
        }
        return head;
    }
};