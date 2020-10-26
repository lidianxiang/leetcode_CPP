/*

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

*/


#include <iostream>
using namespace std;
#include <vector>


class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        /*
            二分查找
        */
        for (int i=0; i<numbers.size(); ++i){
            int low = i+1, high = numbers.size() - 1;
            while(low <= high){
                int mid = (high - low) / 2 + low;
                // 固定第一个数，然后寻找第二个数，第二个数等于目标值减去第一个数的差。
                if (numbers[mid] == target - numbers[i]){
                    return {i+1, mid+1};
                }
                // 当第二个数（target值减去第一个数）的值小于中间值，右边界缩小
                else if (numbers[mid] > target - numbers[i]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};


class Solution2{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        /*
            双指针
        */
        int low = 0, high = numbers.size() - 1;
        while (low < high){
            int sum = numbers[low] + numbers[high];
            if (sum == target){
                return {low+1, high+1};
            }
            else if (sum < target){
                ++low;
            }
            else{
                --high;
            }
        }
        return {-1, -1};
    }
};