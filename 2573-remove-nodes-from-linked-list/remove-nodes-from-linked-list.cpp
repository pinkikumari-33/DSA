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
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;


        while(curr != nullptr) {
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        ListNode* curr = head;
        ListNode* next = head->next;

        ListNode* dummy = new ListNode(0);
        dummy->next = curr;
        

        while(next != nullptr) {
            if(curr->val > next->val) {
                curr->next = next->next;
                next = next->next;
            }
            else {
                curr = curr->next;
                next = next->next;  
            }
        }

        ListNode* res = reverse(dummy->next);
        return res;
    }
};