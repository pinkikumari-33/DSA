class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;
        ListNode* temp = head;

        while(temp){
            length++;
            temp = temp->next;
        }
        if(length == n){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        int pos = length - n;
        temp = head;

        while(pos > 1){
            temp = temp->next;
            pos--;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};