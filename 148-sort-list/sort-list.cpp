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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(left != nullptr && right != nullptr){
            if(left->val <= right->val){
                ListNode* newNode = new ListNode(left->val);
                temp->next = newNode;
                left = left->next;
                temp = temp->next;
            }
            else{
                ListNode* newNode = new ListNode(right->val);
                temp->next = newNode;
                right = right->next;
                temp = temp->next;
            }
        }

        if(left != nullptr){
            temp->next = left;
        }else{
            temp->next = right;
        }

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* middle = findMiddle(head);

        ListNode* right = middle->next;

        middle->next = nullptr;

        ListNode* left = head;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        head = mergeSort(head);
        return head;   
    }
};