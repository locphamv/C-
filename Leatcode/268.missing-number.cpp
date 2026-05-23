/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a[10005]={0};
        for(int i=0; i<nums.size();i++)
        {
            a[nums[i]]++;
        }
        for(int i=0; i<nums.size()+1;i++)
        {
            if(a[i]==0)
            {
                return i;
            }
        }
        return 1;
    }
};
// @lc code=end

