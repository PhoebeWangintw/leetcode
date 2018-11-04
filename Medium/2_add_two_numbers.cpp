// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : PhoebeWangintw
// Date   : 2018-11-04

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/*
1. Adding the values in two input nodes together as the result value 
in output node. 
2. Repeat 1. till we reach the end of both input node.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        ListNode *cur = l1 ? l1 : l2;
        int result = 0;
        bool add_one = false;

        while (cur || add_one)
        {
            result = add_one ? 1 : 0;

            if (l1)
            {
                result += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                result += l2->val;
                l2 = l2->next;
            }

            add_one = result > 9;
            l3->next = new ListNode(result % 10);
            l3 = l3->next;

            cur = l1 ? l1 : l2;
        }

        return head->next;
    }
};