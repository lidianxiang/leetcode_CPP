/*

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

*/

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>


class Solution{
public:
    int majorityElement(vector<int>& nums){
        /*
           哈希映射（键为num，值为出现的次数），遍历数组维护一个最大键，并返回这个最大键 
        */
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for(int num: nums){
            ++counts[num];
            if(counts[num] > cnt){
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};


class Solution2{
public:
    int majorityElement(vector<int>& nums){
        /*
            nums排序后，中位数一定为众数
        */
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


class Solution3{
public:
    int majorityElement(vector<int>& nums){
        /*
            因为超过中位数的数组下标被众数占据了，这样我们随机挑选一个下标对应的元素并验证，有很大的概率能找到众数。

        */
        while (true)
        {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums)
                if (num == candidate)
                    ++count;
            if (count > nums.size() / 2)
                return candidate;
        }
        return -1;
    }
};


class Solution4{
public:
    int majorityElement(vector<int>& nums){
        /*
            Boyer-Moore算法：如果我们把众数记为+1，把其他数记为−1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。
        */
        int candidate = -1;
        int count = 0;
        for (int num : nums)
        {
            if (num == candidate)
                ++count;
            else if (--count < 0)
            {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};