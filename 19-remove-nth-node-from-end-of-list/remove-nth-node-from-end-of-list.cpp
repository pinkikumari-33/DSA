class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head -> next == nullptr) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr-> next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr || head->next == nullptr) return nullptr;

        head = reverseList(head);

        ListNode* temp = head;
        ListNode* prev = nullptr;

        if(n == 1){
            head = head->next;
            delete temp;
            head = reverseList(head);
            return head;
        }

        temp = head;
        while(n >  1){
            prev = temp;
            temp = temp->next;
            n--;
        }

        prev->next = temp->next;
        delete temp;

        head = reverseList(head);

        return head;

    }
};