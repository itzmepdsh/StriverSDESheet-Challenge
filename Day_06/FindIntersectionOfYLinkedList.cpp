/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if(len1<len2){
            int diff = len2-len1;
            while(diff--){
                temp2 = temp2->next;
            }
        }
        else{
            int diff = len1-len2;
            while(diff--){
                temp1 = temp1->next;
            }
        }
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2)return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};