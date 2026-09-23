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
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* Last = NULL;
        ListNode* First = head;
        ListNode* Second = head->next;
        ListNode* Next = NULL;

        while (Second != NULL && First != NULL) {
            Next = Second->next;
            Second->next = First;
            First->next = Next;
            if (Last != NULL) {
                Last->next = Second;
            } else {
                head = Second;
            }
            Last = First;
            First = Next;
            if (First != NULL)
                Second = Next->next;
        }
        return head;
    }
};