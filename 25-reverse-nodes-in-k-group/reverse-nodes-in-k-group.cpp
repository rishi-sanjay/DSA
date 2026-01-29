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
        ListNode* prev = nullptr;
        int n = 0;
        ListNode* z = head;
        ListNode* y = head;
        ListNode* rem = head;
        ListNode* temp = head;
        bool st = 0;
        while (temp != nullptr) {
            if (n != k) {
                ListNode* aage = temp->next;
                temp->next = prev;
                prev = temp;
                temp = aage;
                n++;
            }
            if (n == k and st == false) {
                head = prev;
                y = temp;
                prev = nullptr;
                n = 0;
                st = 1;
            }
            if (n == k) {
                z->next = prev;
                z = y;
                y = temp;
                n = 0;
                prev = nullptr;
            }
        }
        if (n != k) {
            ListNode* stt = prev;
            ListNode* one = nullptr;
            while (stt) {
                ListNode* fu = stt->next;
                stt->next = one;
                one = stt;
                stt = fu;
            }
            prev = one;
        }
        z->next = prev;
        return head;
    }
};