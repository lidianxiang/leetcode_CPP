/*

给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

示例 1：
输入：nums = [10,2]
输出："210"

示例 2：
输入：nums = [3,30,34,5,9]
输出："9534330"

示例 3：
输入：nums = [1]
输出："1"

示例 4：
输入：nums = [10]
输出："10"

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution{   // 贪心解法
public:
    string largestNumber(vector<int>& nums){
        vector<string> str;
        for(auto num: nums){
            str.push_back(to_string(num));
        }
        // 使用lambda比较elements
        auto cmp = [](string left, string right){
            return left + right > right + left;
        };

        sort(str.begin(), str.end(), cmp);
        stringstream ss;
        for(auto c: str){
            ss << c;
        }

        string ans = str.str();
        // 处理特殊情况，开头为0的情况
        if (ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};