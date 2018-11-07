// Source: https://leetcode.com/problems/longest-common-prefix/
// Author: PhoebeWangintw
// Date: 2018/11/07

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty()) return "";
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i)
        {
            int j_min = min(prefix.length(), strs[i].length());

            for (int j = 0; j < j_min; ++j)
            {
                if (prefix[j] != strs[i][j])
                {
                    prefix = prefix.substr(0, j);
                    continue;
                }
            }

            if (prefix.length() > j_min) prefix = prefix.substr(0, j_min);
        }
        return prefix;
    }
};