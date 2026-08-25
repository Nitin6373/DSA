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

        if (head != NULL && head->next != NULL) {

        ListNode* Prev = head;
            ListNode* Curr = head->next;

            while (Curr != NULL) {

                if (Prev->val == Curr->val) {
                    Prev->next = Curr->next;
                    delete (Curr);
                    Curr = Prev->next;
                } else {
                    Prev = Prev->next;
                    Curr = Curr->next;
                }
            }
        }
        return head;
    }
};