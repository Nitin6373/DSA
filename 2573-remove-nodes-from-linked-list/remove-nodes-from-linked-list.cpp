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
    ListNode* Reverse(ListNode* Start) {
        ListNode* Prev = NULL;
        ListNode* Curr = Start;

        while (Curr != NULL) {
            ListNode* NextNode = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = NextNode;
        }

        return Prev;
    }

    ListNode* removeNodes(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        head = Reverse(head);

        stack<int> st;
        st.push(head->val);

        ListNode* Temp2 = head;
        ListNode* Temp = head->next;

        while (Temp != NULL) {
            while(!st.empty() && st.top() <= Temp->val){
                st.pop();
            }

            if(!st.empty()){
                // Now Delete The Temp Node
                Temp2->next = Temp->next;
                Temp = Temp->next;
                continue;
            }

            Temp2 = Temp ;
            st.push(Temp->val);
            Temp = Temp->next;
        }

        head = Reverse(head);
        return head;
    }
};