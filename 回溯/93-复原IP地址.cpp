/*

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

*/


#include<iostream>
using namespace std;
#include<vector>


class Solution {    // 回溯
private:
    vector<string> res;   // 保存结果
    void backtrack(string&s, int startIndex, int pointNum){  // pointNum: 添加逗点的数量
        if (pointNum == 3){
            // 判断第四段子字符串是否合法，合法就放进res中
            if (isValid(s, startIndex, s.size()-1)){
                res.push_back(s);
            }
            return;
        }
        for(int i=startIndex; i<s.size(); i++){
            if (isValid(s, startIndex, i)){   // 判断[startIndex, i]这个区间的子串是否合法
                s.insert(s.begin()+i+1, '.');  // 在i后面插入一个逗点
                pointNum++;   // 统计逗点的数量加一
                backtrack(s,i+2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;   // 回溯
                s.erase(s.begin()+i+1);  // 回溯删掉逗点
            }else break;   // 不合法，直接结束本层循环
        }
    }
    // 判断字符串s在左闭右闭区间所组成的数字是否合法
    bool isValid(const string& s, int start, int end){
        if (start > end){
            return false;
        }
        if (s[start] == '0' && start != end){  // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for(int i=start; i<=end; i++){
            if (s[i] > '9' || s[i] < '0'){
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255){
                return false;
            }
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s){
        res.clear();
        backtrack(s, 0, 0);
        return res;
    }
};