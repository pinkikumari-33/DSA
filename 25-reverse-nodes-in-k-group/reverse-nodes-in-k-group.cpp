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
    ListNode* reverseList(ListNode* head) {
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

    ListNode* kthNodeFunction(ListNode* head,int k){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = head;

        while(k > 1 && temp != nullptr){
            temp = temp->next;
            k--;
        }

        if( k > 0 && temp == nullptr) return nullptr;

        return temp;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* kthNode = nullptr;
        ListNode* temp = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while(temp != nullptr){

            kthNode = kthNodeFunction(temp,k);
            
            if(kthNode == nullptr){
                if(prev != nullptr){
                    prev->next = temp;
                }
                break;
            }

            next = kthNode->next;
            kthNode->next = nullptr;
            kthNode = reverseList(temp);

            if(temp == head){
                head = kthNode;
            }else{
                prev->next = kthNode;
            }

            prev = temp;
            temp = next;
        }

        return head;
    }
};