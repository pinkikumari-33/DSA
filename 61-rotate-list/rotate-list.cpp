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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;

        int len = 1;
        ListNode* tail = head;

        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }

        k = k % len;
        int node = len - k;

        if(k == 0) return head;

        ListNode* temp = head;

        while(node > 1){
            node--;
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
        
    }
};