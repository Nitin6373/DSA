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
    void Reverse(ListNode* GivenLeft, int times) {
        ListNode* Prev = NULL;
        ListNode* Curr = GivenLeft;

        while (times--) {
            ListNode* Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }

        return;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;

        ListNode* Temp = head;
        int Size = 0;

        while (Temp != NULL) {
            Temp = Temp->next;
            Size++;
        }

        ListNode* PrevLeft = head;
        ListNode* Left = head->next;
        ListNode* Right = NULL;
        ListNode* NextNode = NULL;
        int Count = 2;
        int Used = 1;

        while (Used < Size) {
            Right = Left;

            if (Size - Used >= Count) {
                for (int i = 0; i < Count - 1; i++) {
                    if (Right == NULL)
                        break;
                    Right = Right->next;
                }
                if (Count % 2 == 0) {
                    NextNode = Right->next;
                    Reverse(Left, Count);
                    PrevLeft->next = Right;
                    PrevLeft = Left;
                    Left = NextNode;
                } else {
                    PrevLeft->next = Left;
                    PrevLeft = Right;
                    Left = Right->next;
                }
                Used += Count;
            } else {
                for (int i = 0; i < (Size-Used) - 1; i++) {
                    Right = Right->next;
                }
                if ((Size - Used) % 2 == 0) {
                    NextNode = Right->next;
                    Reverse(Left, Size - Used);
                    PrevLeft->next = Right;
                    PrevLeft = Left;
                    Left = NextNode;
                    Used += Size-Used;
                } else {
                    PrevLeft->next = Left;
                    break;
                }
            }
            Count++;
        }

        return head;
    }
};