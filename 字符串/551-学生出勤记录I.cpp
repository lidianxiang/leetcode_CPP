/*

给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

你需要根据这个学生的出勤记录判断他是否会被奖赏。

示例 1:

输入: "PPALLP"
输出: True
示例 2:

输入: "PPALLL"
输出: False

*/


#include<iostream>
using namespace std;


class Solution{
public:
    bool checkRecord(string s){
        // 当没有超过一个A且出现超过两个L的情况下，返回true，否则返回false
        return s.find("A", s.find("A")+1) == -1 && s.find("LLL") == -1;
    }
};