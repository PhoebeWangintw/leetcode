/*
Source: https://leetcode.com/problems/two-sum/description/
Author: PhoebeWangintw
Date: 2018/10/30
*/

/*
Given an array of integers, return indices of the two numbers such 
that they add up to a specific target. You may assume that each input 
would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*
Brute force solution takes O(n^2). It simply iterations the array 
twice to see if there're two different elements that add up to the target 
number. We can further speed up this by using some spaces in exchange 
for better time complexity. And hash table is a suitable candidate.
We can use hash table to store the value and index of the array as key/ 
value pair. Then, we can check the complement of target - nums[i] using 
the loopup table, which only takes O(1). 
The total time complexity is reduced to O(n), which is the same as space 
complexity.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto found = m.find(complement);
            if ((found != m.end()) && (found->second != i)) {
                result.push_back(i);
                result.push_back(found->second);
                break;
            }
            m.insert({nums[i], i});
        }
        
        return result;
    }
};