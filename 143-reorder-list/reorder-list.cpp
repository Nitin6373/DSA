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
    void reorderList(ListNode* head) {
        ListNode *Slow = head;
        ListNode *Fast = head;

        while(Fast != NULL && Fast->next != NULL){
            Slow = Slow->next;
            Fast = Fast->next->next;
        }

        ListNode *Midd = Slow;
        ListNode *New;
        ListNode *Temp = NULL;
        Slow = head;
        Fast = head->next;

        while(Midd->next != Fast){
            New = Midd;
            while(New->next != Temp){
                New = New->next;
            }
            Slow->next = New;
            New->next = Fast;
            Temp = New;
            Slow = Fast;
            Fast = Fast->next;
        }
        Midd->next = NULL;
    }
};