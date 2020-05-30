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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* current = head, * next, *temp,*prev;
        int count = 0;
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        next = current->next;
        while(next!=NULL){
            if(current == head){
                temp = current->next;
            }
            prev = current;
            current->next = next->next;
            current = next;
            next = current->next;
            count++;
        }
        if(count%2 == 0) current->next = temp;
        else prev->next = temp;
        return head;
    }
};
