/*

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();

        // 统计零的个数
        int numZeroes = 0;
        for (int i = 0; i < n; i++)
        {
            numZeroes += (nums[i] == 0);
        }

        // 创建一个新的数组用于临时存放排序数组
        vector<int> ans;
        // 遍历数组，将不为零的数暂时存放在ans中
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                ans.push_back(nums[i]);
            }
        }

        // 然后将零放入临时数组ans中
        while (numZeroes--)
        {
            ans.push_back(0);
        }

        // 将临时数组ans的值赋值给原数组nums
        for (int i = 0; i < n; i++)
        {
            nums[i] = ans[i];
        }
    }

};


class Solution2{
public:
    void moveZeroes(vector<int>& nums){

        int nonZeroCount = 0;
        // 先遍历数组将非零的数放到数组的最前面
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[nonZeroCount++] = nums[i];
            }
        }
        // 在从nonZeroCount位置开始遍历数组，将后续位置设置为0
        for (int i = nonZeroCount; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};


class Solution3{
public:
    void moveZeroes(vector<int>& nums){
        /*
            双指针：一个指针从头到尾遍历数组，一个指针由于记录非零数字的位置
                   并在原地进行交换
        */
        for(int lastNonZeroFoundAt=0, cur=0; cur<nums.size();cur++){
            if (nums[cur] != 0){
                swap(nums[lastNonZeroFoundAt], nums[cur]);
            }
        }
    }
};