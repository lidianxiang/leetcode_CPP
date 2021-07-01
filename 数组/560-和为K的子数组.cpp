/*

给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

*/


#include<iostream>
using namespace std;
#include<vector>
#include<map>


class Solution{     // 枚举
public:
    int subarraySum(vector<int>& nums, int k){
        int count = 0;
        for(int start=0; start <= nums.size(); start++){
            int sum = 0;
            for(int end=start; end >= 0; end--){
                sum += nums[end];
                if (sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};


class Solution2{    // 前缀和 + 哈希表
public:
    int subarraySum(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for(aut& num: nums){
            pre += num;
            if (mp.find(pre - k) != mp.end()){
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};