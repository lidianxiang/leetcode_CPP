/*

给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 回溯（超时）
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int maxNum = INT_MIN;
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
            maxNum = max(maxNum, nums[i]);
        }

        int target = total / k;
        if ((total % k != 0 ) || (maxNum > total)){
            return false;
        }

        bool* used = new bool[n];
        memset(used, 0, sizeof(bool) * n);
        return dfs(nums, target, target, k, 0, used);
    }

    bool dfs(vector<int>& nums, int target, int rest, int group, int start, bool* used){
        if(group == 0){
            return true;
        }
        int n = nums.size();
        for(int i=start; i<n; i++){
            if (!used[i]){
                used[i] = true;
                if ((nums[i] < rest && dfs(nums, target,  rest-nums[i],  group, i+1, used)) || (nums[i] == rest && dfs(nums, target, target, group-1, 0, used))){
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
};


class Solution2 {    // 动态规划
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k==1)
            return true;
        int nums_size=nums.size();
        sort(nums.begin(),nums.end());
        int sum=0;
        for (int i:nums)
            sum+=i;
        int target=sum/k;
        //剪枝
        if (sum%k!=0 || nums.back()>target)
            return false;
        //全集
        int ALL=(1<<nums_size)-1;
        vector<bool> dp(ALL+1,false);
        dp.at(0)=true;
        vector<int> cur_sum(ALL+1,0);
        for (int i=0;i<=ALL;++i)
        {
            if (!dp.at(i))
                continue;
            for (int j=0;j<nums_size;++j)
            {
                if ((i&(1<<j))!=0)
                    continue;
                int nxt=i|(1<<j);
                //不同状态转移到同一个状态nxt，他们最后cur_sum[nxt]都是一样的，所以没必要重新计算
                if (dp.at(nxt))
                    continue;
                if (nums.at(j)+(cur_sum.at(i)%target)<=target)
                {
                    dp.at(nxt)=true;
                    cur_sum.at(nxt)=cur_sum.at(i)+nums.at(j);
                }
                //因为提前按照升序排列，剪枝
                else
                    break;
            }
        }
        return dp.at(ALL);
    }
};
