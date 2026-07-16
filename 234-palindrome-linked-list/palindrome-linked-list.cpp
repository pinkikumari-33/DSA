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
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != nullptr) slow = slow->next;
        
        slow = reverseList(slow);

        ListNode* check = slow;
        slow = head;
        fast = check;

        while(fast != nullptr){
            if(slow->val != fast-> val){
                return false;
            }

            slow = slow->next;
            fast = fast->next;
        }

        return true;

    }
};