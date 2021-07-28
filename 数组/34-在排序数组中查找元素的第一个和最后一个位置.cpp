/*

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]

*/


#include<iostream>
using namespace std;
#include<vector>

class Solution {   // 二分查找
public:

    int binarySearch(vector<int>& nums, int target, bool lower){
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)){
                right = mid - 1;
                ans = mid;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false) - 1;
        if (leftIndex <= rightIndex && rightIndex < nums.size() && nums[leftIndex] == target && nums[rightIndex] == target){
            return vector<int>{leftIndex, rightIndex};
        }
        return vector<int>{-1, -1};
    }
};