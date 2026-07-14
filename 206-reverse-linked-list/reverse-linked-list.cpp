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
    ListNode* reverseNode(ListNode* head,ListNode* prev,ListNode *next){
        if(head == nullptr) return prev;

        next = head->next;
        head->next = prev;
        prev = head;
        head = next;

        return reverseNode(head,prev,next);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        head = reverseNode(head,prev,next);

        return head;
    }
};