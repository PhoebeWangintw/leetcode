// Sourch: https://leetcode.com/problems/palindrome-number/
// Author: PhoebeWangintw
// Data: 2018/11/04

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if ((x < 0) || ((x % 10 == 0) && (x != 0)))
            return false;

        int reversed = 0;

        while (x > reversed)
        {
            reversed *= 10;
            reversed += (x % 10);
            x /= 10;
        }

        return (x == reversed) || (x == (reversed / 10));
    }
};