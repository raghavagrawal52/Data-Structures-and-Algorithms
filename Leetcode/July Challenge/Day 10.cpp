/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        stack<Node*> s;
        
        while(head || !s.empty()) {
            if(head && head->child) {
                if(head->next)
                    s.push(head->next);
                head->next = head->child;
                head->next->prev = head;
                head->child = nullptr;
            }
            else if(!head->next && !s.empty()) {
                head->next = s.top();
                head->next->prev = head;
                s.pop();
            }
            if(head)
                head = head->next;
        }
        
        return temp;
    }
};
