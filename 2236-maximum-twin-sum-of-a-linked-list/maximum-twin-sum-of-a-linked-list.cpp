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
    ListNode* reverseList(ListNode* &head) {
        if(head == nullptr) return nullptr;

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode* next;

        while(curr != nullptr){
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* start = start = reverseList(slow);
        ListNode* temp = head;
         
        int ans = 0;

        while(start != nullptr && temp!= nullptr){
            int sum = start->val + temp->val;
            ans =  max(sum,ans);

            start = start->next;
            temp = temp->next;
        }

        return ans;
    }
};