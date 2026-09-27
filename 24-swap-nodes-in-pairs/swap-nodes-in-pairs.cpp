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
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* temp = nullptr;

        while(curr != nullptr && curr->next != nullptr) {
            next = curr->next;

            temp = next->next;

            next->next = curr;
            curr->next = temp;
            if(prev) prev->next = next;
            else head = next;

            prev = curr;
            curr = curr->next;
        }

        return head;

    }
};