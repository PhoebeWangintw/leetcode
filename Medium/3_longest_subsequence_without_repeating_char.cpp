// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: PhoebeWangintw
// Date: 2018/11/05

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
A naive way to solve this problem is to iterate the string twice.
The first loop is used to read new character. As for the second loop, 
it is used to check if the newly read character is duplicated or not. 
Also, we use two variables to record the start and end of substring, 
which is similar to the concept of sliding windows.
However, it takes O(n^2) to complete the whole process. A good way to 
speed up this is to use hash table to record the occurred character 
and its position. By doing this, we only have to loop against the string 
once.
*/

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0, i = 0;
        map<char, int> m;

        // sliding window, [i, j)
        for (int j = 0; j < s.length(); ++j)
        {
            auto found = m.find(s[j]);
            if (found != m.end())
            {
                // find repeated character
                i = max(found->second + 1, i);
            }
            m[s[j]] = j;  // update the hash table
            max_len = max(j - i + 1, max_len);
        }

        return max_len;
    }
};