/*

给定一个包含 非负数 的数组和一个目标 整数 k ，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，且总和为 k 的倍数，即总和为 n * k ，其中 n 也是一个整数。

示例 1：
输入：[23,2,4,6,7], k = 6
输出：True
解释：[2,4] 是一个大小为 2 的子数组，并且和为 6。

示例 2：
输入：[23,2,6,4,7], k = 6
输出：True
解释：[23,2,6,4,7]是大小为 5 的子数组，并且和为 42。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{     // 双指针（超时）
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        int n = nums.size();
        for(int left=0; left<n-1; left++){
            for(int right=left+1; right<n; right++){
                int sum = 0;
                for(int i=left; i<=right; i++){
                    sum += nums[i];
                }
                if (sum == k ||(sum % k == 0 && k != 0)){
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution2{   // 前缀和（超时）
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        int n = nums.size();

        vector<int> prefix(n+1);
        prefix[0] = 0;
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        for(int left=0; left<n-1; left++){
            for(int right=left+1; right<n; right++){
                int sum = prefix[right+1] - prefix[left];
                if (sum == k || (k != 0 && sum % k == 0))
                    return true;
            }
        }
        return false;
    }
};


class Solution3{     
        /*
            连续子数组和为k的倍数，可以对前缀和 sum 进行取余，取余之后的 sum 必然小于k，
            此时若在当前位置之前存在一个前缀和等于 sum的情况，则说明两个位置中间的和必为 0 
            同时也一定是 k的倍数，由此将问题转化为是否存在连续子数组和为 0 的问题。

        */
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(k != 0)
                sum %= k;
            if (mp.find(sum) != mp.end()){
                if(i - mp[sum] > 1)
                    return true;
            }else{
                mp[sum] = i;
            }
        }
        return false;
    }
};