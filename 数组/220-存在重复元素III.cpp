/*

给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。

示例 1：
输入：nums = [1,2,3,1], k = 3, t = 0
输出：true

示例 2：
输入：nums = [1,0,1,1], k = 1, t = 2
输出：true

示例 3：
输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false

*/

#include<iostream>
using namespace std;
#include<vector>


class Solution{     // 滑动窗口 + 集合
public:
    bool containsNearByAlmostDuplicate(vector<int>& nums, int k, int t){
        int n = nums.size();
        set<int> rec;
        for(int i=0; i<n; i++){
            auto iter = rec.lower_bound(max(nums[i], INT_MIN+t) - t);
            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t){
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k){
                rec.erase(nums[i-k]);
            }
        }
        return false;
    }
};