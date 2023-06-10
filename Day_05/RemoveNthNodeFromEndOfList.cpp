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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)return NULL;
        int i=1;
        ListNode* fast = head;
        while(i<n){
            fast = fast->next;
            i++;
        }
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast->next != NULL){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev == NULL)//corner case
            return head->next;
        else
            prev->next = slow->next;
        delete slow;
        return head;
    }
};