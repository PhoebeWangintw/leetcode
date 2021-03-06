// Source: https://leetcode.com/problems/valid-parentheses/
// Author: PhoebeWangintw
// Date: 2018/11/07

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (auto &c : s)
        {
            if (c == '(' || c == '[' || c == '{') { stk.push(c);}
            else
            {
                if (!stk.empty())
                {
                    char top = stk.top();
                    stk.pop();
                    if (c == ')' && top != '(') {return false;}
                    else if (c == ']' && top != '['){return false;}
                    else if (c == '}' && top != '{'){return false;}
                } else {return false;}
            }
        }

        return stk.empty();
    }
};