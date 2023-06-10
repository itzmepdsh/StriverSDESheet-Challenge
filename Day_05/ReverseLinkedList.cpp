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
        
        //Recursive Approach
        //base case
        if(!head)return NULL;
        if(head->next == NULL)return head;
        //recursive case
        ListNode* recHead = reverseList(head->next);
        ListNode* recTail = recHead;
        while(recTail->next != NULL){
            recTail = recTail->next;
        }
        recTail->next = head;
        head->next = NULL;
        return recHead;

        //Iterative Approach
        // if(!head)return head;
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // while(curr != NULL){
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // return prev;
    }
};