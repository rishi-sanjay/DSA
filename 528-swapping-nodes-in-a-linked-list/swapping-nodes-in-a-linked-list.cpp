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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* sl;
        ListNode* pre = nullptr;
        ListNode* x = nullptr;
        ListNode* rem = nullptr;
        ListNode* temp = head;
        int n = k, c = 0;
        while (temp && n != 0) {
            c += 1;
            if (c == k) {
                x = pre;
                sl = temp;
                rem = temp->next;
            }
            pre = temp;
            temp = temp->next;
            n--;
        }
        ListNode* fa = head;
        ListNode* y = nullptr;
        while (temp != nullptr) {
            y = fa;
            fa = fa->next;
            temp = temp->next;
        }
        if (sl == fa)
            return head;

        if (y != nullptr && y != sl)
            y->next = sl;
        else if (y == nullptr)
            head = sl;
        if (fa != x)
            sl->next = fa->next;
        else
            sl->next = fa;
        if (x != nullptr && x != fa)
            x->next = fa;
        else if (x == nullptr)
            head = fa;
        if (fa != rem)
            fa->next = rem;
        else
            fa->next = sl;
        return head;
    }
};