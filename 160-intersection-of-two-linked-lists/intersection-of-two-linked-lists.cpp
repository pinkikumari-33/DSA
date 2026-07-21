/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int n1 = 1;
        int n2 = 1;

        while(temp1 != nullptr){
            n1++;
            temp1 = temp1->next;
        }

        while(temp2 != nullptr){
            n2++;
            temp2 = temp2->next;
        }

        int diff = abs(n1 - n2);

        temp1 = headA;
        temp2 = headB;

        if(n1 > n2){
            for(int i = 1; i <= diff; i++){
                temp1 = temp1->next;
            }
        }else{
            for(int i = 1; i <= diff; i++){
                temp2 = temp2->next;
            }
        }

        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 == temp2) return temp1;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return nullptr;
    }
};