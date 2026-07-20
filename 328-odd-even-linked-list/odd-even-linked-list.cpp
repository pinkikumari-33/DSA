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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* oddhead = head;
        ListNode* evenhead = head->next;

        ListNode* oddtail = head;
        ListNode* eventail = head->next;

        while(eventail != nullptr && eventail->next != nullptr){
            oddtail->next = eventail->next;
            oddtail = oddtail->next;

            eventail->next = oddtail->next;
            eventail = eventail->next;
        }

        oddtail->next = evenhead;
        return oddhead;

    }
};