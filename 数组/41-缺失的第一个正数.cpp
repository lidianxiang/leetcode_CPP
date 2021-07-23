/*

给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

示例 1：
输入：nums = [1,2,0]
输出：3

示例 2：
输入：nums = [3,4,-1,1]
输出：2

示例 3：
输入：nums = [7,8,9,11,12]
输出：1

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 哈希表
public:
    int firstMissingPositive(vector<int>& nums){
        int n = nums.size();
        // 将小于0的数置为n+1
        for(int& num: nums){
            if (num <= 0){
                num = n + 1;
            }
        }
        // 将数组nums中的每个数对应的数组的索引的数置为负数
        for(int i=0; i<n; i++){
            int num = abs(nums[i]);
            if (num < n){
                nums[num-1] = -abs(nums[num-1]);
            }
        }
        // 遍历数组，第一个出现的正数的索引值就是缺失值
        for(int i=0; i<n; i++){
            if (nums[i] > 0){
                return i+1;
            }
        }
        // 如果数组中没有正数，则返回数组长度加一
        return n + 1;
    }
};


class Solution2{     // 原地哈希
public:
    int firstMissingPositive(vector<int>& nums){
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for(int i=0; i<n; i++){
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};