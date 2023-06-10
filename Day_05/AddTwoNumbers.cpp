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
    void insertAtHead(ListNode*& head, int val){
        ListNode* n = new ListNode(val);
        n->next = head;
        head = n;
    }
    void insertAtTail(ListNode*& head, int val){
        if(!head){
            insertAtHead(head,val);
            return;
        }
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        ListNode* n = new ListNode(val);
        tail->next = n;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = NULL;
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1 != NULL && temp2 != NULL){
            int add = temp1->val + temp2->val + carry;
            insertAtTail(sum,add%10);
            carry = add/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
            int add = temp1->val + carry;
            insertAtTail(sum,add%10);
            carry = add/10;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            int add = temp2->val + carry;
            insertAtTail(sum,add%10);
            carry = add/10;
            temp2 = temp2->next;
        }
        if(carry == 1)insertAtTail(sum,1);
        return sum;
    }
};