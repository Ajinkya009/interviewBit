/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *temp = A;
    int d;
    d = A->val;
    if(A == NULL){
        return A;
    }
    while(temp->next!=NULL){
        if(temp->next->val==d){
            temp->next = temp->next->next;
            d = temp->val;
        }
        else{
            temp = temp->next;
            d = temp->val;
        }
    }
    return A;
}
