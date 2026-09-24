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

        if(head == NULL || head->next == NULL || k == 1)
            return head;

        int n = 0;

        ListNode* Temp = head;
        while (Temp != NULL) {
            n++;
            Temp = Temp->next;
        }

        ListNode *Last = NULL;
        ListNode *First = NULL;
        ListNode *Sec = NULL;


        ListNode* Prev = NULL;
        ListNode* Curr = head;

        int Count = 0;

        while (Curr != NULL) {
            if(n >= k){
                ListNode *Next = Curr->next;
                Curr->next = Prev;
                Prev = Curr;
                Curr = Next;
                Count++;
                if(Count == 1){
                    First = Prev;
                }
                else if(Count == k){
                    Sec = Prev;

                    if(Last == NULL){
                        head = Sec;
                    }
                    else{
                        Last->next = Sec;
                    }

                    First->next = Curr;
                    Last = First;
                    Count = 0;
                    n -= k;
                    Prev = NULL;
                }
                continue;
            }
            break;
        }

        return head;
    }
};