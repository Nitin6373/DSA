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
    bool isPalindrome(ListNode* head) {
        ListNode *Slow = head;
        ListNode *First = head;

        while(First != NULL && First->next != NULL){
            Slow = Slow->next;
            First = First->next->next;
        }

        ListNode *Prev = NULL;
        ListNode *Curr = Slow;
        ListNode *Next;

        while(Curr != NULL){
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }

        First = Prev;
        Slow = head;

        while(First != NULL){
            if(Slow->val == First->val){
                Slow = Slow->next;
                First = First->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};