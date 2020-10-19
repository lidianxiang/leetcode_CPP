/*

给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

*/

#include<iostream>
using namespace std;
#include<vector>


class Solution{
    int removeDuplicates(vector<int>& nums){
        /*
            使用双指针
        */   
        if (nums.empty())
            return 0;        // 当nums为空的情况下，直接返回0
        int slowIndex = 0;   // 慢指针
        // 循环数组
        for(int fastIndex=0; fastIndex<(nums.size() - 1); fastIndex++){
            // 当两个快指针的值不同的时候
            if (nums[fastIndex] != nums[fastIndex+1]){
                // 将后一个快指针的值赋值给慢指针，慢指针同时加一
                nums[++slowIndex] = nums[fastIndex+1];
            }
        }
        return slowIndex+1;  // 返回去重后的长度
    }
};