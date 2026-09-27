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
        //-------------- Bettter Approach using three pointer -------

        // Object of listNode class
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* first = head;

        while(first != nullptr && first->next != nullptr) {
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;

            prev->next = second;
            prev = first;
            first = prev->next;

        }

        // ------- My Approach using four pointer ------------

        // while(curr != nullptr && curr->next != nullptr) {
        //     next = curr->next;

        //     temp = next->next;

        //     next->next = curr;
        //     curr->next = temp;
        //     if(prev) prev->next = next;
        //     else head = next;

        //     prev = curr;
        //     curr = curr->next;
        // }

        return dummy->next;

    }
};