/*

给定一个整数数组，判断是否存在重复元素。

如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

*/

#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <unordered_map>


class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        /*
            使用集合来判断是否有重复的元素      
        */
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};


class Solution2{
public:
    bool containsDuplicate(vector<int>& nums){
        /*
        使用排序的方式
        */
       sort(nums.begin(), nums.end());
       for(int i=1; i<nums.size(); i++){
           if (nums[i] == nums[i-1]){
               return true;
           }
       }
       return false;
    }
};


class Solution3{
public:
    bool containsDuplicate(vector<int>& nums){
        /*
            使用哈希map
        */
        unordered_map<int, int> map;
        for(int num: nums){
            map[num]++;
            if(map[num] > 1)
                return true;
        }
        return false;
    }
};