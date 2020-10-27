/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

*/


#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    /*
        使用hash策略，map数据结构来记录数组元素和对应元素的下标
    */
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k)
                return true;
            map[nums[i]] = i;
        }
        return false;
    }
};


class Solution2{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        /*
            使用滑动窗口的思想
        */
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end())  // 当找到了重复的值时，返回true
            {
                return true;
            }
            set.insert(nums[i]);  // 否则将此时的值放入值set容器中
            if (set.size() > k)  // 当set容器的长度大于k时，移动窗口，始终保持窗口大小为k
            {
                set.erase(nums[i - k]);  // 滑动窗口的最大长度为k
            }
        }
        return false;   // 遍历完vector容器还没找到，则返回false
    }
};