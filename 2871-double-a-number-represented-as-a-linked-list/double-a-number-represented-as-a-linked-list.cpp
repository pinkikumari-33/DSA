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
    ListNode* doubleIt(ListNode* head) {
        stack<int> s1;
        stack<int> s2;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(head != nullptr){
            s1.push(head->val);
            head = head->next;
        }

        int pro = 1; int carry = 0;

        while(!s1.empty()){
            pro = s1.top()*2 + carry;
            s1.pop();

            s2.push(pro % 10);
            carry = pro/10;
            pro = 1;
        }

        if(carry == 1) s2.push(1);

        while(!s2.empty()){
            ListNode* newNode = new ListNode(s2.top());
            s2.pop();

            temp->next = newNode;
            temp = temp->next;
        }

        return dummy->next;
    }
};