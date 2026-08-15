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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *Fast = head;

        while(Fast != NULL && Fast->next != NULL){
            slow = slow->next;
            Fast = Fast->next->next;
            if(slow==Fast){
                slow = head;
                while(slow!=Fast){
                    slow = slow->next;
                    Fast = Fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};