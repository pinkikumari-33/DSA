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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = nullptr;
        ListNode* temp = head;

        int n = 1;
        int val = 0;

        while(temp != nullptr) {
            if(n == k) {
                first = temp;
            }
            n++;
            temp = temp->next;
        }

        val = n - k;

        temp = head;

        while(val > 1) {
            temp = temp->next;
            val--;
        }

        int tempVal = first->val;

        first->val = temp->val;
        temp->val = tempVal; 

        return head;
    }
};