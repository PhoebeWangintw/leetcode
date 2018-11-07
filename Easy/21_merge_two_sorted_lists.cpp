// Source: https://leetcode.com/problems/merge-two-sorted-lists/description/
// Author: PhoebeWangintw
// Date: 2018/11/07

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                ListNode *new_node = new ListNode(l1->val);
                l3->next = new_node;
                l3 = new_node;
                l1 = l1->next;
            }
            else
            {
                ListNode *new_node = new ListNode(l2->val);
                l3->next = new_node;
                l3 = new_node;
                l2 = l2->next;
            }
        }

        ListNode *l4 = l1 ? l1 : l2;
        while (l4)
        {
            ListNode *new_node = new ListNode(l4->val);
            l3->next = new_node;
            l3 = new_node;
            l4 = l4->next;
        }

        return head->next;
    }
};