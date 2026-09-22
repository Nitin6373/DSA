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
    ListNode* Reverse(ListNode *head){
        ListNode *Prev = NULL;
        ListNode *Curr = head;

        while(Curr != NULL){
            ListNode *Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }

        return Prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        head = Reverse(head);
        
        ListNode *Temp = head;

        int n = 0;

        while(Temp->next != NULL){
            n++;
            Temp = Temp->next;
        }
        n++;

        k = k % n;

        while(k){
            Temp->next = head;
            ListNode *NextHead = head->next;
            head->next = NULL;
            Temp = head;
            head = NextHead;
            k--;
        }

        head = Reverse(head);

        return head;
    }
};