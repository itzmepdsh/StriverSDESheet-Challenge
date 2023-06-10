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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //base case
        if(!list1 && !list2)return NULL;
        if(!list1)return list2;
        if(!list2)return list1;
        //recursive case
        ListNode* res = NULL;
        if(list1->val < list2->val){
            res = list1;
            ListNode* recList = mergeTwoLists(list1->next,list2);
            res->next = recList;
        }
        else{
            res = list2;
            ListNode* recList = mergeTwoLists(list1,list2->next);
            res->next = recList;
        }
        return res;
    }
};