/*

给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]

示例 3：
输入：nums = [1,-1], k = 1
输出：[1,-1]

示例 4：
输入：nums = [9,11], k = 2
输出：[11]

示例 5：
输入：nums = [4,-2], k = 2
输出：[4]

*/


#include<iostream>
using namespace std;
#include<vector>
#include<queue>


class Solution{    // 暴力求解：超时 时间复杂度：O((n-k+1)* k)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> ans;
        for(int i=k-1; i<nums.size(); i++){
            ans.push_back(*max_element(nums.begin()+i-k+1, nums.begin()+i+1));
        }
        return ans;
    }
};

class Solution2{    // 滑动窗口就要想到优先队列
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for(int i=0; i<k; i++){
            q.emplace(nums[i], i);
        }

        vector<int> ans = {q.top().first};
        for(int i=k; i<n; i++){
            q.emplace(nums[i], i);
            while(q.top().second <= i - k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};