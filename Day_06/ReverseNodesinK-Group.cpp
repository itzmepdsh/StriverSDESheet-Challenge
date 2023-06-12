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
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* helper(ListNode* head, int len ,int k){
        //base case
        if(len < k){
            return head;
        }
        //recursive case
        int i = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Tail = curr;
        while(i<k){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            i++;
        }
        Tail->next = helper(curr,len-k,k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        return helper(head,len,k);
    }
};