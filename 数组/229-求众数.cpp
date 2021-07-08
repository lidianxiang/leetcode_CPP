/*

给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

示例 1：
输入：[3,2,3]
输出：[3]

示例 2：
输入：nums = [1]
输出：[1]

示例 3：
输入：[1,1,1,3,3,2,2,2]
输出：[1,2]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>


class Solution {   // 哈希表
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty())
            return {};

        vector<int> res;
        int N = nums.size();
        unordered_map<int, int> mp;
        for(const auto& num: nums){
            mp[num]++;
        }

        for(const auto& m: mp){
            if (m.second > N / 3){
                res.push_back(m.first);
            }
        }
        return res;
    }
};



class Solution2{   // Moore Voting
public:
    vector<int> majorityElement(vector<int>& nums){
        if (nums.empty())
            return {};

        int m = 0;
        int cm = 0;
        int n = 0;
        int cn = 0;
        for(const auto& num: nums){
            if (m == num){
                cm++;
            }else if (n == num){
                cn++;
            }else if (cm == 0){
                m = num;
                cm++;
            }else if (cn == 0){
                n = num;
                cn++;
            }else{
                cm--;
                cn--;
            }
        }
        cm = 0;
        cn = 0;
        for(const auto& num: nums){
            if (num == m){
                cm++;
            }else if (num == n){
                cn++;
            }
        }

        vector<int> res;
        if (cm > nums.size() / 3){
            res.push_back(m);
        }
        if (cn > nums.size() /3 ){
            res.push_back(n);
        }
        return res;
    }
};