/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> q;

        vector<Node*> res;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp == nullptr){
                for(int i = 0; i < res.size()-1; i++){
                    res[i]->next = res[i+1];
                }

                res[res.size()-1]->next = nullptr;
                
                res.clear();

                if(q.size() > 0){
                    q.push(nullptr);
                    continue;
                }
                else{
                    break;
                }
            }

            res.push_back(temp);

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

        return root;
    }
};