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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)return true;
        ListNode* fast = head->next;
        ListNode* midPoint = head;
        while(fast != NULL && fast->next != NULL){
            midPoint = midPoint->next;
            fast = fast->next->next;
        }
        ListNode* head2 = midPoint->next;
        midPoint->next = NULL;
        ListNode* revHead2 = reverse(head2);
        ListNode* strt = head;
        while(revHead2 != NULL){
            if(strt->val != revHead2->val)return false;
            strt = strt->next;
            revHead2 = revHead2->next;
        }
        return true;
    }
};