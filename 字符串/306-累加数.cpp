/*

累加数是一个字符串，组成它的数字可以形成累加序列。

一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。

说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

示例 1:

输入: "112358"
输出: true 
解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2:

输入: "199100199"
输出: true 
解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 回溯
public:
    bool isAdditiveNumber(string num) {
        vector<long long> res;
        return backtrack(num, 0, res);
    }

private:
    bool backtrack(string S, int start, vector<long long>& res){
        int size = S.size();
        if (start >= size){
            return res.size() >= 3;
        }
        int maxSplitSize = S[start] == '0' ? 1: 11;
        for(int i=1; i+start <= size && (i <= maxSplitSize); i++){
            auto numStr = S.substr(start, i);
            // cout << "numStr = " << numStr <<endl;
            long long num = stoll(numStr);
            int rsize = res.size();
            if (rsize >= 2 && (res[rsize - 1] + res[rsize - 2] != num)){
                continue;
            }
            res.push_back(num);
            if (backtrack(S, start+i, res)){
                return true;
            }
            res.pop_back();
        }
        return false;
    }
};
