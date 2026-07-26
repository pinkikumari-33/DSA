class node{
public :
    int data;
    int minValue;
    node* next;

    node(int val,int minVl){
        data = val;
        minValue =  minVl;
        next = nullptr;
    }
};

class MinStack {
public:
    node* head;
    int minValue = INT_MAX;

    MinStack() {
        head = nullptr;
    }
    
    void push(int value) {
        if(head == nullptr){
            minValue = value;
            node* newNode = new node(value,minValue);

            head = newNode;
            return;
        }

        minValue = min(value,head->minValue);
        node* newNode = new node(value,minValue);

        
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {
        if(head == nullptr || head->next == nullptr){
            node* temp = head;
            delete temp;
            head = nullptr;
            return;
        } 

        node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->data;
    }
    
    int getMin() {
        return head->minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */