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
    bool hasCycle(ListNode *head) {
        struct ListNode *Slow ;
        struct ListNode *First;
        Slow = head;
        First = head;

        while(First != NULL && First->next != NULL){
            // Move The POinters
            // Fast will be faster than Slow
            Slow = Slow -> next;
            First = First->next->next;

            if(Slow == First){
                return true;
            }
        }
        return false;
    }
};