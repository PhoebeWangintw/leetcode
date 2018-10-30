/*
Source: https://leetcode.com/problems/reverse-integer/description/
Author: PhoebeWangintw
Date: 2018/10/30
*/


/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store 
integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 
when the reversed integer overflows.
*/

/*
Reversing an interger (or a string) is similar to doing push and pop 
operations. We do "pop" by dividing x by 10 while do "push" by adding 
x % 10 to the result variable. 
Also, we have to take extra care about the maximum/ minimum value that
an interger can store. Therefore, we check the overflow by evaluating 
whether the result variable is greater that INT_MAX/10 or smaller than 
INT_MIN/10 before multiplying it by 10.
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while (x != 0) {
            if (result > INT_MAX/10 || result < INT_MIN/10) return 0;
            result *= 10;
            result += x % 10;
            x /= 10;
        }
    
        return result;
    }
};