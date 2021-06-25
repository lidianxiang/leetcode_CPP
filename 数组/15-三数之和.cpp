/*

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：
输入：nums = []
输出：[]

示例 3：
输入：nums = [0]
输出：[]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{    // 排序 + 双指针
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        // 排序
        sorted(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int first=0; first<n; first++){
            // 当出现重复元素的情况，直接跳过
            if (first > 0 && nums[first] == nums[first-1]){
                continue;
            }
            int third = n - 1;
            int target = -nums[first];
            for(int second=first+1; second<n; second++){
                // 当出现重复元素的情况，直接跳过
                if (second>first+1 && nums[second] == nums[second-1]){
                    continue;
                }
                // 当双指针指向的值之和大于target时，右指针左移
                while(second < third && nums[second] + nums[third] > target){
                    --third;
                }
                // 当两指针相遇时，即停止
                if (second == third){
                    break;
                }
                if (nums[second] + nums[third] == target){
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};